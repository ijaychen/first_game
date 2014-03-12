///*************************************************************************
//	> File Name: packet.h
//	> Author: cjj
//	> Created Time: Sun 02 Mar 2014 10:27:03 AM CST
// ************************************************************************/
#ifndef PACKET_H
#define PACKET_H
#include <stdio.h>
#include <string.h>
#include "global.h"
namespace common{

typedef	unsigned short ushort;
typedef unsigned int uint;


typedef enum MsgVersion
{
	VerFirst = 1
}EnumMsgVersion;

typedef enum MsgType
{
	None = 0,
	//for chat
	MsgChatWorld = 1,
	MsgChatPrivate,
	MsgChatChannel,

	//for action
	MsgActMove = 10,
	MsgActAttack
}EnumMsgType;

class MsgHead
{
public:
	MsgHead():m_msg_version(EnumMsgVersion::VerFirst), m_msg_type(EnumMsgType::None){}
	
	inline void SetMsgType(EnumMsgType _msgType)
	{
		m_msg_type = _msgType;
	}
	
	ushort GetMsgType() const
	{
		return m_msg_type;
	}

	inline void SetMsgVersion(EnumMsgVersion _msgVersion)
	{
		m_msg_version = _msgVersion;
	}

	inline void SetMsgLen(unsigned int _msgLen)
	{
		m_msg_len = _msgLen;
	}

	int GetMsgLen() const 
	{
		return m_msg_len;
	}

	void test(){ printf("ver:%d, type:%d size:%d\n", m_msg_version, m_msg_type, sizeof(EnumMsgType)); }
private:
	ushort m_msg_version;
	ushort m_msg_type;
	ushort m_msg_len;
};


class ChatMsg
{
public:
	ChatMsg():m_msg_len(0){ memset(m_chat_msg, 0, sizeof(m_chat_msg));}
	void SetChatMsg(const char * _msg, int _len)
	{
		if(_len > CHAT_MSG_MAX_LEN)
		{
			/*rizhi*/
			printf("chat msg max len : %d, your msg len is: %d", CHAT_MSG_MAX_LEN, _len);
		}
		memcpy(m_chat_msg, _msg, _len);
		m_msg_len = _len;
	}
	void SetTargetId(int _targetId)
	{
		m_targetId = _targetId;
	}
	bool SendStream();

	void test(){printf("Msg: %s, len: %d", m_chat_msg, m_msg_len);}
private:
	int m_targetId;
	int m_msg_len;
	char m_chat_msg[CHAT_MSG_MAX_LEN];
};

}//end of namespace common
#endif
