
vpath = ./base:./include
objects = chatPacket.o gameServer.o inputSocketStream.o msgPacketFactory.o outputSocketStream.o \
		  player.o playerManager.o main.o logger.o utils.o

gameServer : $(objects)
	g++ -o gameServer $(objects)

logger.o : ./base/logger.h ./base/logger.cpp
	g++ -c ./base/logger.cpp
utils.o : ./base/file/utils.h 
	g++ -c ./base/file/utils.cpp
player.o : player.h playerInfo.h inputSocketStream.h outputSocketStream.h msgPacketFactory.h
chatPacket.o : chatPacket.h msgPacket.h ./include/packet.h inputSocketStream.h outputSocketStream.h player.h 
gameServer.o : gameServer.h playerManager.h socketSet.h command_define.h ./base/file/utils.h
inputSocketStream.o : inputSocketStream.h command_define.h
msgPacketFactory.o : msgPacketFactory.h msgPacket.h chatPacket.h
outputSocketStream.o : outputSocketStream.h command_define.h
playerManager.o : playerManager.h player.h
main.o : main.cpp gameServer.h
#	g++ -c ./base/logger.cpp ./base/file/utils.cpp
clean:
	rm gameServer *.o
