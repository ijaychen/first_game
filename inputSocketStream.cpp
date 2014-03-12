/*************************************************************************
	> File Name: inputSocketStream.cpp
	> Author: cjj
	> Created Time: Sat 08 Mar 2014 10:44:14 AM CST
 ************************************************************************/

#include "inputSocketStream.h"
#include <string.h>
#include <unistd.h>

namespace game_server{

InputSocketStream::InputSocketStream(int sock)
{
	m_buff = new char[STREAM_BUFFER_SIZE];
	if(!m_buff)
	{
		//log
		return;
	}
	m_tempBuff = new char[STREAM_BUFFER_SIZE];
	if(!m_tempBuff)
	{
		//log
		delete m_buff;
		return;
	}

	m_nHead = m_nTail = 0;
	m_nFreeSize = m_nTotalSize = STREAM_BUFFER_SIZE;

	m_socket = sock;

}

InputSocketStream::~InputSocketStream()
{
	if(m_buff)
	{
		delete m_buff;
	}
	if(m_tempBuff)
	{
		delete m_tempBuff;
	}
}

bool InputSocketStream::PeekStream(char * buf, int len)
{
	if(0 == len)
	{
		//log
		return false;
	}
	if((m_nTotalSize - m_nFreeSize) < len)
	{
		//log
		return false;
	}
	if(m_nTail > m_nHead)
	{
		memcpy(buf, &m_buff[m_nHead], len);
	}
	else
	{
		int rightLen = m_nTotalSize - m_nHead;
		if(rightLen >= len)
		{
			memcpy(buf, &m_buff[m_nHead], len);
		}
		else
		{
			memcpy(buf, &m_buff[m_nHead], rightLen);
			memcpy(&buf[rightLen], m_buff, len - rightLen);
		}
	}
	return true;
}

bool InputSocketStream::ReadStream(char * buf, int len)
{
	if(!PeekStream(buf, len))
	{
		//log
		return false;
	}
	m_nFreeSize += len;
	m_nHead = (m_nHead + len) % m_nTotalSize;
	return true;
}

bool InputSocketStream::FillStream()
{
	memcpy(m_tempBuff, 0, sizeof(m_tempBuff));
	int len = read(m_socket, m_tempBuff, SOCKET_BUFFER_SIZE);
	if(-1 == len || 0 == len)
	{
		//发送玩家离开消息
		//写日志
	}
	if(m_nFreeSize < len)
	{
		if(!DoubleSize())
		{
			//log
			return false;
		}
	}
	if(m_nTail > m_nHead)
	{
		int rightLen = m_nTotalSize - m_nTail;
		if(rightLen < len)
		{
			memcpy(&m_buff[m_nTail], m_tempBuff, rightLen);
			memcpy(m_buff, &m_tempBuff[rightLen], len - rightLen);
		}
		else
		{
			memcpy(&m_buff[m_nTail], m_tempBuff, len);
		}
	}
	else
	{
		memcpy(&m_buff[m_nTail], m_tempBuff, len);	
	}
	m_nTail = (m_nTail + len) % m_nTotalSize;
	m_nFreeSize -= len;
	return true;
}

bool InputSocketStream::DoubleSize()
{
	char * temp = m_buff;
	m_buff = new char[m_nTotalSize * 2];
	if(!m_buff)
	{
		//log
		m_buff = temp;
		return false;
	}
	if(m_nTail > m_nHead)
	{
		memcpy(m_buff, &temp[m_nHead], m_nTotalSize - m_nFreeSize);
	}
	else
	{
		memcpy(m_buff, &temp[m_nHead], m_nTotalSize - m_nHead);
		memcpy(&m_buff[m_nTotalSize - m_nHead], temp, m_nTail);
	}
	m_nFreeSize += m_nTotalSize;
	m_nTotalSize *= 2;
	m_nHead = 0;
	m_nTail = m_nTotalSize - m_nFreeSize;
	delete []temp;
	return true;
}

}
