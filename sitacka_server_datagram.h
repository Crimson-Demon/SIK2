#ifndef SITACKA_SERVER_DATAGRAM_H
#define SITACKA_SERVER_DATAGRAM_H

#include <string>
#include "sitacka_server_events.h"

#define SERVER_MAX_DATAGRAM_SIZE 512 // 512 bytes

// UDP
// big endian

class ServerDatagram {
	unsigned int gameID; // 4 bytes unsigned int
	Event* events; // 

public:

	virtual char* serialize();
	virtual void deserialize(char*);

private:

}

#endif // SITACKA_SERVER_DATAGRAM_H