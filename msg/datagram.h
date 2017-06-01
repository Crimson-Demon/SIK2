#ifndef SITACKA_DATAGRAM_H
#define SITACKA_DATAGRAM_H

#include <string>

// UDP
// big endian

class Datagram {

public:
	virtual char* serialize() = 0;
	virtual void deserialize(char*) = 0;

private:

};

#endif // SITACKA_DATAGRAM_H