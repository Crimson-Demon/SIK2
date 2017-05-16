#ifndef SITACKA_GAMESTATE_H
#define SITACKA_GAMESTATE_H

#include <vector> // Vector
#include <string> // String
#include <tuple> // Tuple
#include <map> // Map
#include <utility> // Pair

#include "sitacka_player.h"
#include "sitacka_server_event.h"

typedef std::tuple<std::Pair<unsigned double, unsigned double>, unsigned double> SnakeHead;
typedef bool** GameBoard;

class GameState {
	unsigned int gameID; // as in server datagram
	std::map<Player, SnakeHead>
	std::vector<Event> eventHistory;
	GameBoard board;
}

#endif // SITACKA_GAMESTATE_H
