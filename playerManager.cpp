/*************************************************************************
	> File Name: playerManager.cpp
	> Author: cjj
	> Created Time: Mon 10 Mar 2014 02:22:30 PM CST
 ************************************************************************/
#include "playerManager.h"
#include <stdio.h>

namespace game_server{

bool PlayerManager::AddPlayer(int _sock)
{
	Player * player = new Player(_sock, NULL);
	if(player)
	{
		m_playerMap.insert(std::map<int, Player *>::value_type(_sock, player));
	}
}


bool PlayerManager::DelPlayer(int _sock)
{
	Player * player = NULL;
	//find
	std::map<int, Player*>::iterator iter = m_playerMap.find(_sock);
	if(iter != m_playerMap.end())
	{
		player = iter->second;
		//delete player
		delete player;
	}	
	//erase map
	m_playerMap.erase(iter);
	return true;
}

bool PlayerManager::RecvPacket(int _clientSocket)
{
	Player * player = m_playerMap[_clientSocket];

	if(player)
	{
		player->GetInputPacket();
	}
	return true;
}

bool PlayerManager::ProcessPacket()
{
	Player * player = NULL;
	for(PlayerMapIter iter = m_playerMap.begin(); iter != m_playerMap.end(); ++iter)
	{
		player = iter->second;
		if(player)
		{
			player->ProcessPacket();
			player->SendMessage();
		}
	}
	return true;
}

}
