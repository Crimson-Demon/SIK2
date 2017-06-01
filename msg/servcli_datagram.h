#ifndef SITACKA_SERVCLI_DATAGRAM_H
#define SITACKA_SERVCLI_DATAGRAM_H

#include <string>
#include <cstdint>
#include <vector>
#include "../server/server_event.h"

#define SERVER_MAX_DATAGRAM_SIZE 512 // 512 bytes

// UDP
// big endian

class ServerClientDatagram {

public:
    ServerClientDatagram(std::uint32_t gameID) : gameID(gameID) { }
    ~ServerClientDatagram() { }
    void addEvent(const Event& event);

	char* serialize();
	void deserialize(char* msg);

private:
    std::uint32_t gameID; // 4 bytes unsigned int
    std::vector<Event> events; //
};

#endif // SITACKA_SERVCLI_DATAGRAM_H
