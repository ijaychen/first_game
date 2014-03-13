/*************************************************************************
	> File Name: player.h
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 06:06:05 PM CST
 ************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>


namespace game_server
{
class InputSocketStream;
class OutputSocketStream;
class MsgPacketFactory;
class PlayerInfo;

class Player
{
public:
	Player(int _sock, PlayerInfo * _playerInfo = 0);
	virtual ~Player();

	bool GetInputPacket();
	bool SetOutputPacket(const char * buff, int len);
	bool ProcessPacket();
	bool SendMessage();
private:
	int m_socket;
	std::string m_playerName;

	InputSocketStream * m_pInputStream;
	OutputSocketStream * m_pOutputStream;

	MsgPacketFactory * m_pMsgPacketFactory;

};


typedef std::map<int, Player*> PlayerMap;
typedef std::map<int, Player*>::iterator PlayerMapIter;


}
#endif
