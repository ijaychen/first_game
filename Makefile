testPacket: chatPacket.h inputSocketStream.h outputSocketStream.h msgPacket.h playerInfo.h player.h player.cpp msgPacketFactory.h msgPacketFactory.cpp test.cpp gameServer.h gameServer.cpp playerManager.cpp playerManager.h
	g++ main.cpp chatPacket.cpp player.cpp gameServer.cpp  msgPacketFactory.cpp inputSocketStream.cpp outputSocketStream.cpp playerManager.cpp -std=c++0x
