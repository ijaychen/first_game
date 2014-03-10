/*************************************************************************
	> File Name: outputSocketStream.cpp
	> Author: cjj
	> Created Time: Sun 09 Mar 2014 02:20:15 PM CST
 ************************************************************************/

#include "outputSocketStream.h"
#include "command_define.h"

namespace game_server{

OutputSocketStream::OutputSocketStream(int sock)
{
	m_buff = new char[STREAM_BUFFER_SIZE];
	if(!m_buff)
	{
		//log
		return;
	}
	m_nHead = m_nTail = 0;
	m_nFreeSize = m_nTotalSize = STREAM_BUFFER_SIZE;
	m_socket = sock;
}

OutputSocketStream::~OutputSocketStream()
{
	if(m_buff)
		delete m_buff;
}

bool OutputSocketStream::SendStream()
{
	if(m_nTotalSize == m_nFreeSize)
	{
		//log
		return false;
	}
	if(m_nHead < m_nTail)
	{
		write(m_socket, m_buff, m_nTotalSize - m_nFreeSize);
	}
	else
	{
		int rightLen = m_nTotalSize - m_nHead;
		write(m_socket, &m_buff[m_nHead], rightLen);
		write(m_socket, m_buff, m_nTtail);
	}
	m_nHead = 0;
	m_nTail = 0;
	return true;
}


bool OutputStream::WriteStream(const char * buff, int len)
{
	if(0 == len)
	{
		//log
		return false;
	}
	if(m_nFreeSize < len)
	{
		if(!DoubleSize())
		{
			//log
			return false;
		}
	}
	if(m_nHead < m_nTail)
	{
		int rightLen = m_nTotalSize - m_nTail;
		if(rightLen < len )
		{
			memcpy(&m_buff[m_nTtail], buff, rightLen);
			memcpy(&m_buff[0], buff[rightLen], len - rightLen);
		}
		else
		{
			memcpy(&m_buff[m_nTail], buff, len);
		}
	}
	else
	{
		memcpy(&m_buff[m_nTail], buff, len);
	}
	m_nTail = (m_nTail + len) % m_nTotalSize;
	m_nFreeSize -= len;
	return true;
}

bool OutputSocketStream::DoubleSize()
{
	char * temp = m_buff;
	m_buff = new char[m_nTotalSize * 2];
	if(!m_buff)
	{
		//log
		m_buff = temp;
		return false;
	}
	if(m_nHead < m_nTail)
	{
		memcpy(m_buff, &temp[m_nHead], m_nTotalSize - m_nFreeSize);
	}
	else
	{
		memcpy(buff, &temp[m_nHead], m_nTotalSize - m_nHead);
		memcpy(&buff[m_nTotalSize - m_nHead], temp, m_nTail);
	}
	m_nTotalSize *= 2;
	m_nFreeSize += m_nTotalSize;
	m_nHead = 0;
	m_nTail = m_nTotalSize - m_nFreeSize;
	return true;
}

}
