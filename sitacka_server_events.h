#ifndef SITACKA_SERVER_EVENTS_H
#define SITACKA_SERVER_EVENTS_H

#include <string>

enum class EventType {NEW_GAME, PIXEL, PLAYER_ELIMINATED, GAME_OVER}; // 0, 1, 2, 3

class EventData {

}

class NewGameEventData: public EventData {
	unsigned int maxx; // 4 bytes, width of board
	unsigned int maxy; // 4 bytes, height of board
	vector<string> playerNames // each playerName ends with '\0';
}

class PixelEventData: public EventData {
	unsigned char playerNumber; // 1 byte
	unsigned int x; // 4 bytes, unsigned integer, x-axis coord
	unsigned int y; // 4 bytes, unsigned integer, y-axis coord
}

class PlayerEliminatedEventData: public EventData {
	unsigned char playerNumber; // 1 byte
}

class GameOverEventData: public EventData {

}

class Event {
	unsigned int length; // 4 bytes unsigned integer, equals size(eventNo)+size(eventType)+size(eventData)
	unsigned int eventNo; // 4 bytes unsigned integer, for each game consequtive values starting at 0
	unsigned char eventType; // 1 byte
	EventData* eventData; // depends on event type
	unsigned int crc32; // control sum based on length to eventData using CRC-32-IEEE

}

#endif // SITACKA_SERVER_EVENTS_H