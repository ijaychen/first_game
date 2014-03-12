/*************************************************************************
	> File Name: chatPacket.cpp
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 01:16:18 PM CST
 ************************************************************************/

#include <iostream>
#include "./include/packet.h"
#include "inputSocketStream.h"
#include "outputSocketStream.h"
#include "player.h"
#include "chatPacket.h"

using namespace std;

namespace game_server
{

bool ChatPacket::ReadStream(InputSocketStream &_inStream)
{
	return false;
}

bool ChatPacket::WriteStream(OutputSocketStream &_outStream)
{
	return false;
}

bool ChatWorldPacket::Execute(Player * _player)
{
	std::cout << "chat world execute!\n";
	return true;

}

bool ChatChannelPacket::Execute(Player * _player)
{
	std::cout << "chat channel execute!\n";
	return true;
}

bool ChatPrivatePacket::Execute(Player * _player)
{
	std::cout << "chat private execute!\n";
	return true;
}

}
