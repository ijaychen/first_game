///*************************************************************************
//	> File Name: packet.h
//	> Author: cjj
//	> Created Time: Sun 02 Mar 2014 10:27:03 AM CST
// ************************************************************************/
#ifndef PACKET_H
#define PACKET_H
#include <stdio.h>
namespace common{
typedef	unsigned short ushort;

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
	MsgChatFaction,

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

	inline void SetMsgVersion(EnumMsgVersion _msgVersion)
	{
		m_msg_version = _msgVersion;
	}

	inline void SetMsgLen(unsigned int _msgLen)
	{
		m_msg_len = _msgLen;
	}
	void test(){ printf("ver:%d, type:%d size:%d\n", m_msg_version, m_msg_type, sizeof(EnumMsgType)); }
private:
	ushort m_msg_version;
	ushort m_msg_type;
	ushort m_msg_len;
};

}//end of namespace common
#endif
