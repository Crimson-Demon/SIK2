#include "servcli_datagram.h"

void ServerClientDatagram::addEvent(const Event& event) {
    events.push_back(event);
}

char* ServerClientDatagram::serialize() {

}

void ServerClientDatagram::deserialize(char* msg) {

}