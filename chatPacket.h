/*************************************************************************
	> File Name: chatPacket.h
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 10:31:18 AM CST
 ************************************************************************/

#ifndef CHAT_PACKET_H
#define CHAT_PACKET_H

#include "msgPacket.h"


namespace game_server
{
class ChatMsg;

class ChatPacket : public MsgPacket
{
public:
	bool ReadStream(InputSocketStream &_inStream);
	bool WriteStream(OutputSocketStream &_outStream);
	virtual bool Execute(Player * _Player) {}
private:
	ChatMsg * m_chatPacket;
};


class ChatChannelPacket : public ChatPacket
{
public:
	virtual bool Execute(Player *_player);	
};


class ChatWorldPacket : public ChatPacket
{
public:
	virtual bool Execute(Player * _player);
};

class ChatPrivatePacket : public ChatPacket
{
public:
	virtual bool Execute(Player * _player);
};

}
#endif
