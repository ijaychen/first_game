/*************************************************************************
	> File Name: test.cpp
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 02:55:39 PM CST
 ************************************************************************/

#include "msgPacketFactory.h"
#include "player.h"

int main()
{
	game_server::Player player11;
	game_server::MsgPacketFactory * factory = game_server::MsgPacketFactory::GetInstance();
	game_server::MsgPacket *pack1 = factory->CreatePacket(common::EnumMsgType::MsgChatWorld);
	game_server::MsgPacket *pack2 = factory->CreatePacket(common::EnumMsgType::MsgChatPrivate);
	game_server::MsgPacket *pack3 = factory->CreatePacket(common::EnumMsgType::MsgChatChannel);

	pack1->Execute(&player11);
	pack2->Execute(&player11);
	pack3->Execute(&player11);
	return 0;
}

