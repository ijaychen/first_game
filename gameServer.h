/*************************************************************************
	> File Name: gameServer.h
	> Author: cjj
	> Created Time: Wed 12 Mar 2014 09:03:35 AM CST
 ************************************************************************/
#ifndef GAME_SERVER_H
#define GAME_SERVER_H

namespace game_server{

#include <sys/select.h>

class PlayerManager;
class SocketSet;

class GameServer
{
public:
	static GameServer * GetInstance()
	{
		static GameServer _instance;
		return &_instance;
	}
	bool StartServer();
	bool Work();
	bool ProcessCommand();

private:
	PlayerManager * m_playerManager;		
	int m_serverSocket;
	SocketSet * m_clientSet;
	fd_set m_fdReads;
private:
	bool InitSocket(int nPort);
	bool InitSelect();
	int AcceptClient();
	int GetMaxfd() const;

private:
	GameServer();
	GameServer(const GameServer &);
	GameServer & operator= (const GameServer&);
};

}

#endif
