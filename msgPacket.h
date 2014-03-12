/*************************************************************************
	> File Name: MsgPacket.h
	> Author: cjj
	> Created Time: Fri 07 Mar 2014 09:46:51 AM CST
 ************************************************************************/

#ifndef MSG_PACKET_H
#define MSG_PACKET_H


namespace game_server
{
class InputSocketStream;
class OutputSocketStream;
class Player;

class MsgPacket
{
public:
	virtual bool ReadStream(InputSocketStream &_inStream){};
	virtual bool WriteStream(OutputSocketStream &_outStream){};
	virtual bool Execute(Player * _player){};

};

}

#endif
