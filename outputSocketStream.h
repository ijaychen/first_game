/*************************************************************************
	> File Name: outputSocketStream.h
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 01:41:23 PM CST
 ************************************************************************/

#ifndef OUTPUT_SOCKET_STREAM_H
#define OUTPUT_SOCKET_STREAM_H

namespace game_server
{

class OutputSocketStream
{
public:
	OutputSocketStream(int sock);
	virtual ~OutputSocketStream();

	bool WriteStream(const char * buff, int len);
	bool SendStream();
private:
	bool DoubleSize();

private:
	OutputSocketStream(const OutputSocketStream &);
	OutputSocketStream& operator= (const OutputSocketStream&);

private:
	char * m_buff;
	int m_nHead;
	int m_nTail;
	int m_socket;
	int m_nTotalSize;
	int m_nFreeSize;

};



}



#endif
