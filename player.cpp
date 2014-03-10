/*************************************************************************
	> File Name: player.cpp
	> Author: cjj
	> Created Time: Thu 06 Mar 2014 08:59:17 PM CST
 ************************************************************************/

#include "player.h"
#include "playerInfo.h"
#include "inputSocketStream.h"
#include "outputSocketStream.h"
#include "msgPacketFactory.h"

namespace game_server{

Player::Player(int _sock, PlayerInfo & _playerInfo)
{
	m_socket = _sock;
	m_playerName = _playerInfo.GetPlayerName();
	m_pInputStream = new InputSocketStream(_sock);
	m_pOutputStream = new OutputSocketStream(_sock);
}

Player::~Player()
{
	if(m_pInputStream)
		delete m_pInputStream;
	if(m_pOutputStream)
		delete m_pOutputStream;
}

bool Player::GetInputPacket()
{
	if(m_pInputStream)
		return m_pInputStream->FillStream();
	else
		return false;
}

bool Player::SetOutputPacket(const char * buff, int len)
{
	if(m_pOutputStream)
	{
		return m_pOutoutStream->WriteString(buff, len);
	}
	else
		return false;
}

bool Player::ProcessPacket()
{
	MsgHead packHead;

	if(m_pInputStream->PeekStream((char*)&packHead, sizeof(packHead)))
	{
		if(EnumMsgType::None == packHead.GetMsgType())
		{
			//log
			return false;
		}
	}

}

}
