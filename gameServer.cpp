/*************************************************************************
	> File Name: gameServer.cpp
	> Author: cjj
	> Created Time: Wed 12 Mar 2014 09:22:36 AM CST
 ************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "playerManager.h"
#include "gameServer.h"
#include "socketSet.h"
#include "command_define.h"

namespace game_server
{

GameServer::GameServer()
{
	m_playerManager = PlayerManager::GetInstance();
	if(!m_playerManager)
	{
		//log
		return ;
	}
	m_clientSet = SocketSet::GetInstance();
	if(!m_clientSet)
	{
		//log
		return;
	}
	FD_ZERO(&m_fdReads);
}

bool GameServer::InitSocket(int nPort)
{
	int res = 0;
	m_serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == m_serverSocket)
	{
		//log
		return false;
	}
	sockaddr_in serverAddr = {0};
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(nPort);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	res = bind(m_serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
	if(-1 == res)
	{
		//log
		close(m_serverSocket);
		return false;
	}
	res = listen(m_serverSocket, MAX_SERVER_LISTEN);
	if(-1 == res)
	{
		//log
		close(m_serverSocket);
		return false;
	}

	return true;
}

bool GameServer::InitSelect()
{
	int nMaxFd = GetMaxfd();
	FD_ZERO(&m_fdReads);
	FD_SET(m_serverSocket, &m_fdReads);
	for(SocketSetIter iter = m_clientSet->GetSocketSetBegin(); iter != m_clientSet->GetSocketSetEnd(); ++iter)
	{
		FD_SET(*iter, &m_fdReads);
	}
	struct timeval tv = {0};
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	int res = select(nMaxFd + 1, &m_fdReads, NULL, NULL, &tv);
	if(-1 == res)
	{
		//log
		return false;
	}
	if(FD_ISSET(m_serverSocket, &m_fdReads))
	{
		int clientFd = AcceptClient();
		if(m_playerManager->AddPlayer(clientFd))
		{
			m_clientSet->AddSocket(clientFd);
		}
	}
	for(SocketSetIter sockSetIter = m_clientSet->GetSocketSetBegin(); sockSetIter != m_clientSet->GetSocketSetEnd(); ++sockSetIter)
	{
		if(-1 != *sockSetIter && FD_ISSET(*sockSetIter, &m_fdReads))
		{
			m_playerManager->RecvPacket(*sockSetIter);		
		}
	}
	return true;
}

int GameServer::AcceptClient()
{
	sockaddr_in clientAddr = {0};
	socklen_t len = 0;
	int fdClient = accept(m_serverSocket, (sockaddr*)&clientAddr, &len);
	if(-1 == fdClient)
	{
		//log
		return -1;
	}
	return fdClient;
}

int GameServer::GetMaxfd() const
{
	int nMaxFd = m_clientSet->GetMaxSocket();
	return (nMaxFd > m_serverSocket ? nMaxFd : m_serverSocket);
}

bool GameServer::StartServer()
{
	if(!InitSocket(6675))
	{
		return false;
	}
	if(!InitSelect())
	{
		return false;
	}
	return true;
}

bool GameServer::ProcessCommand()
{
	m_playerManager->ProcessPacket();
	return true;
}

}
