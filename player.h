/*************************************************************************
	> File Name: player.h
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 06:06:05 PM CST
 ************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>

class InputSocketStream;
class OutputSocketStream;

namespace game_server
{
class PlayerInfo;
class Player
{
public:
	Player(){}
	Player(int _sock, PlayerInfo & _playerInfo);
	virtual ~Player();

	bool GetInputPacket();
	bool SetOutputPacket(const char * buff, int len);
	bool ProcessPacket();
private:
	int m_socket;
	std::string m_playerName;

	InputSocketStream * m_pInputStream;
	OutputSocketStream * m_pOutputStream;
};


typedef std::map<int, Player*> PlayerMap;
typedef std::map<int, Player*>::iterator PlayerMapIter;


}
#endif
