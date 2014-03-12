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

Player::Player(int _sock, PlayerInfo * _playerInfo)
{
	m_socket = _sock;
	m_playerName = _playerInfo->GetPlayerName();
	m_pInputStream = new InputSocketStream(_sock);
	m_pOutputStream = new OutputSocketStream(_sock);
	m_pMsgPacketFactory = MsgPacketFactory::GetInstance();
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
		return m_pOutputStream->WriteStream(buff, len);
	}
	else
		return false;
}

bool Player::SendMessage()
{
	m_pOutputStream->SendStream();
}


bool Player::ProcessPacket()
{
	common::MsgHead packHead;
	MsgPacket * pMsgPack = NULL;
	if(m_pInputStream->PeekStream((char*)&packHead, sizeof(packHead)))
	{
		if(common::EnumMsgType::None == packHead.GetMsgType())
		{
			//log
			return false;
		}
		if(m_pInputStream->GetAllPacketSize() < packHead.GetMsgLen())
		{
			//log
			return false;
		}
		m_pInputStream->ReadStream((char*)&packHead, sizeof(packHead));
		pMsgPack = m_pMsgPacketFactory->CreatePacket(packHead.GetMsgType());
		if(pMsgPack)
		{
			pMsgPack->ReadStream(*m_pInputStream);
			pMsgPack->Execute(this);
		}
	}

}

}
