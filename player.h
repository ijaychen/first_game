/*************************************************************************
	> File Name: player.h
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 06:06:05 PM CST
 ************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>

class PlayerInfo;

namespace game_server
{
class Player
{
public:
	Player(int _sock, PlayerInfo & _playerInfo);
	virtual ~Player();

	bool SendMessage(const char * strMessage, int nlen);
private:
	int m_socket;
	std::string m_playerName;
};


typedef std::map<int, Player*> PlayerMap;
typedef std::map<int, Player*>::iterator PlayerMapIter;


}
#endif
