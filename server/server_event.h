#ifndef SITACKA_SERVER_EVENTS_H
#define SITACKA_SERVER_EVENTS_H

#include <string>
#include <vector>
#include <cstdint> // all the sized types

enum class EventType : std::uint8_t {NEW_GAME = 0, PIXEL = 1, PLAYER_ELIMINATED = 2, GAME_OVER = 3};

class EventData {
public:
    EventData() { }
    virtual ~EventData() { }
    virtual std::uint32_t getLength() = 0;
};

class NewGameEventData: public EventData {
public:
    NewGameEventData(std::uint32_t maxx,
                     std::uint32_t maxy,
                     std::vector<std::string> playerNames) : maxx(maxx), maxy(maxy) {
        playerNames = std::vector<std::string>(playerNames);
    }
    ~NewGameEventData() { }
    std::uint32_t getLength() {
        std::uint32_t playerNameLen = 0;
        for(auto playerName = playerNames.begin(); playerName != playerNames.end(); playerName++)
            playerNameLen += static_cast<std::uint32_t >((*playerName).size());
        return (8 + playerNameLen);
    }

private:
	std::uint32_t maxx; // 4 bytes, width of board
	std::uint32_t maxy; // 4 bytes, height of board
	std::vector<std::string> playerNames; // each playerName ends with '\0';
};

class PixelEventData: public EventData {
public:
    PixelEventData(std::uint8_t playerNumber,
                   std::uint32_t x,
                   std::uint32_t y) : playerNumber(playerNumber), x(x), y(y) { }
    ~PixelEventData() { }
    std::uint32_t getLength() {
        return 9;
    }

private:
    std::uint8_t playerNumber; // 1 byte
	std::uint32_t x; // 4 bytes, unsigned integer, x-axis coord
	std::uint32_t y; // 4 bytes, unsigned integer, y-axis coord
};

class PlayerEliminatedEventData: public EventData {
public:
    PlayerEliminatedEventData(std::uint8_t playerNumber) : playerNumber(playerNumber) { }
    ~PlayerEliminatedEventData() { }
    std::uint32_t getLength() {
        return 1;
    }

private:
	std::uint8_t playerNumber; // 1 byte
};

class GameOverEventData: public EventData {
public:
    GameOverEventData() { }
    ~GameOverEventData() { }
    std::uint32_t getLength() {
        return 0;
    }
};

class Event {
public:
    Event(std::uint32_t eventNo,
          EventType eventType) : length(5), eventNo(eventNo), eventType(static_cast<std::uint8_t>(eventType)) { };
    ~Event() { }

    void addEventData(const EventData& eventData) {
        eventDataVec.push_back(eventData);
        length += eventData.getLength();
    }

    void updateCRC32() { }

private:
	std::uint32_t length; // 4 bytes unsigned integer, equals size(eventNo)+size(eventType)+size(eventData)
	std::uint32_t eventNo; // 4 bytes unsigned integer, for each game consequtive values starting at 0
	std::uint8_t eventType; // 1 byte
	std::vector<EventData> eventDataVec; // depends on event type
	unsigned int crc32; // control sum based on length to eventData using CRC-32-IEEE

};

#endif // SITACKA_SERVER_EVENTS_H