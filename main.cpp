/*************************************************************************
	> File Name: main.cpp
	> Author: cjj
	> Created Time: Wed 12 Mar 2014 11:08:32 AM CST
 ************************************************************************/
#include "gameServer.h"

int main()
{
	game_server::GameServer * gameServer = game_server::GameServer::GetInstance();
	while(1)
	{
		gameServer->StartServer();
		gameServer->ProcessCommand();
	}
	return 1;
}
