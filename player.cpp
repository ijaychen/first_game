/*************************************************************************
	> File Name: player.cpp
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 08:59:17 PM CST
 ************************************************************************/

#include "player.h"
#include "playerInfo.h"

namespace game_server{

Player::Player(int _sock, PlayerInfo & _playerInfo)
{
	m_socket = _sock;
	m_playerName = _playerInfo.GetPlayerName();
}

Player::~Player()
{

}

bool Player::SendMessage(const char * strMessage, int nLen)
{
	

}

}
