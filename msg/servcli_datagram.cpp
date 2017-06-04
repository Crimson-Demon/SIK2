#include "servcli_datagram.h"
#include <algorithm> // for_each

void ServerClientDatagram::addEvent(const Event& event) {
    events.push_back(event);
}

char* ServerClientDatagram::serialize() {
    // Count the number of bytes in the whole datagram
    int nBytes = 4; // gameID
    auto countBytes = [&nBytes](const Event& event) -> void { nBytes += event.size(); };
    std::for_each(events.begin(), events.end(), countBytes);

    // Serialize with big endian each byte
    // first the gameID

    // next each event

    //return the serialized data
}

void ServerClientDatagram::deserialize(char* msg) {
    // Count the number of bytes

    // First 4 are gameID

    // parse the events and recreate them into our datagram class
}