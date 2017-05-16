#ifndef SITACKA_CLIENT_DATAGRAM_H
#define SITACKA_CLIENT_DATAGRAM_H

#include "sitacka_datagram.h"

// UDP
// big endian

class ClientDatagram: public Datagram {
	unsigned char[8] sessionID; // 8 bytes, unsigned char
	signed char turnDirection; // 1 bytes, -1 is left, 1 is right, 0 is onwards for the empire!
	unsigned int nextExpectedEvent; // 4 bytes, unsigned int
	char[64] playerName; // 0-64 ASCII symbols, no spaces


public:
	virtual char* serialize();
	virtual void deserialize(char*);

private:

}

#endif // SITACKA_CLIENT_DATAGRAM_H