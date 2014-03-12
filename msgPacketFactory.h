/*************************************************************************
	> File Name: msgPacketFactory.h
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 01:49:19 PM CST
 ************************************************************************/

#ifndef MSG_PACKET_FACTORY_H
#define MSG_PACKET_FACTORY_H

#include "./include/packet.h"
#include "msgPacket.h"
#include "chatPacket.h"

namespace game_server
{

class MsgPacketFactory
{
public:
	static MsgPacketFactory * GetInstance()
	{
		static MsgPacketFactory _instance;
		return &_instance;
	}
	MsgPacket * CreatePacket(unsigned short _type);//common::EnumMsgType _type);
	virtual ~MsgPacketFactory();

private:
	MsgPacketFactory();
	MsgPacketFactory(const MsgPacketFactory&);
	MsgPacketFactory& operator= (const MsgPacketFactory&);

private:
	ChatChannelPacket * pChatChannelMsgPacket;
	ChatWorldPacket * pChatWorldMsgPacket;
	ChatPrivatePacket * pChatPrivateMsgPacket;

};

}



#endif
