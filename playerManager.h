/*************************************************************************
	> File Name: playerManager.h
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 09:33:37 PM CST
 ************************************************************************/

#ifndef PLAY_MANAGER_H
#define PLAY_MANAGER_H

class Player;

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
	bool GetMessage();


private:
	PlayerManager();
};



}


#endif
