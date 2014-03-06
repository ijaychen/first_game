/*************************************************************************
	> File Name: playerInfo.h
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 10:39:05 PM CST
 ************************************************************************/

#ifndef PLAYER_INFO_H
#define PLAYER_INGO_H

#include <string>

namespace game_server
{
class PlayerInfo
{
public:
	std::string GetPlayerName() const
	{
		return m_playerName;
	}

private:
	std::string m_playerName;
	//int m_gold;
	//int m_flower;
	//
};

}

#endif
