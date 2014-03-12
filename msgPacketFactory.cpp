/*************************************************************************
	> File Name: msgPacketFactory.cpp
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 02:06:41 PM CST
 ************************************************************************/

#include "msgPacketFactory.h"

namespace game_server
{

MsgPacketFactory::MsgPacketFactory()
{
	pChatChannelMsgPacket = new ChatChannelPacket;
	pChatWorldMsgPacket = new ChatWorldPacket;
	pChatPrivateMsgPacket = new ChatPrivatePacket;
}

MsgPacketFactory::~MsgPacketFactory()
{
	if(pChatChannelMsgPacket)
		delete pChatChannelMsgPacket;
	if(pChatWorldMsgPacket)
		delete pChatWorldMsgPacket;
	if(pChatPrivateMsgPacket)
		delete pChatPrivateMsgPacket;

}

MsgPacket* MsgPacketFactory::CreatePacket(unsigned short _type)//common::EnumMsgType _type)
{
	MsgPacket * tempPacket = NULL;
	switch(_type)
	{
		case common::EnumMsgType::MsgChatWorld:
		{
			tempPacket = pChatWorldMsgPacket;
		}
		break;
		case common::EnumMsgType::MsgChatPrivate:
		{
			tempPacket = pChatPrivateMsgPacket;
		}
		break;
		case common::EnumMsgType::MsgChatChannel:
		{
			tempPacket = pChatChannelMsgPacket;
		}
		break;
		default:
			tempPacket = NULL;
			break;
	}
	return tempPacket;

}





}
