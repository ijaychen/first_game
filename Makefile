testPacket: chatPacket.h inputSocketStream.h outputSocketStream.h msgPacket.h playerInfo.h player.h player.cpp msgPacketFactory.h msgPacketFactory.cpp test.cpp
	g++ chatPacket.cpp player.cpp test.cpp msgPacketFactory.cpp -std=c++0x
