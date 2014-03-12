/*************************************************************************
	> File Name: playerManager.h
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 09:33:37 PM CST
 ************************************************************************/

#ifndef PLAY_MANAGER_H
#define PLAY_MANAGER_H

#include "player.h"

namespace game_server{


class PlayerManager
{
public:
	static PlayerManager * GetInstance()
	{
		static PlayerManager _instance;
		return &_instance;
	}

	bool AddPlayer(int _sock);
	bool DelPlayer(int _sock);
	bool RecvPacket(int);
	bool ProcessPacket();


private:
	PlayerManager(){}
	PlayerManager(const PlayerManager&);
	PlayerManager & operator=(const PlayerManager &);

private:
	PlayerMap m_playerMap;
};



}


#endif
