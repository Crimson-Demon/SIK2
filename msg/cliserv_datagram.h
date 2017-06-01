#ifndef SITACKA_CLISERV_DATAGRAM_H
#define SITACKA_CLISERV_DATAGRAM_H

#include <string>
#include "datagram.h"

// UDP
// big endian

class ClientServerDatagram: public Datagram {
public:
	char* serialize();
	void deserialize(char*);

private:
	std::uint64_t sessionID; // 8 bytes, unsigned char
	signed char turnDirection; // 1 bytes, -1 is left, 1 is right, 0 is onwards for the empire!
	std::uint32_t nextExpectedEvent; // 4 bytes, unsigned int
	char playerName[65]; // 0-64 ASCII symbols, no spaces
};

#endif // SITACKA_CLISERV_DATAGRAM_H