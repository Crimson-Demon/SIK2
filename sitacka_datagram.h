#ifndef SITACKA_DATAGRAM_H
#define SITACKA_DATAGRAM_H

#include <string>

// UDP
// big endian

class Datagram {

public:

	virtual char* serialize();
	virtual void deserialize(char*);

private:

}

#endif // SITACKA_DATAGRAM_H