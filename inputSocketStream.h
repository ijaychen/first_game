/*************************************************************************
	> File Name: inputSocketStream.h
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 01:40:04 PM CST
 ************************************************************************/

#ifndef INPUT_SOCKET_STREAM_H
#define INPUT_SOCKET_STREAM_H

#include "command_define.h"

namespace game_server
{

class InputSocketStream
{
public:
	InputSocketStream(int sock);
	virtual ~InputSocketStream();
	bool ReadStream(char * buf, int len);
	bool PeekStream(char * buf, int len);
	bool FillStream();
	int GetAllPacketSize() const
	{
		return m_nTotalSize - m_nFreeSize;
	}

private:
	bool DoubleSize();
	InputSocketStream(const InputSocketStream &);
	InputSocketStream& operator= (const InputSocketStream &);
private:
	char * m_buff;
	char * m_tempBuff;
	int m_nHead;
	int m_nTail;
	int m_nFreeSize;
	int m_socket;
	int m_nTotalSize;
};


}

#endif
