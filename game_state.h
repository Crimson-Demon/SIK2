#ifndef SITACKA_GAMESTATE_H
#define SITACKA_GAMESTATE_H

#include <vector> // Vector
#include <string> // String
#include <tuple> // Tuple
#include <map> // Map
#include <utility> // Pair

#include "player.h"
#include "server/server_event.h"

typedef std::tuple<std::pair<unsigned double, unsigned double>, unsigned double> SnakeHead;
typedef bool** GameBoard;

class GameState {

public:
    GameState() { }
    GameState(unsigned int gameID,
              unsigned int boardWidth,
              unsigned int boardHeight) : gameID(gameID), boardWidth(boardWidth), boardHeight(boardHeight) {
        board = new bool*[boardWidth];
        for(int i = 0; i < boardWidth; i++)
            board[i] = new bool[boardHeight];
    }

    ~GameState() {
        for(int i = 0; i < boardWidth; i++)
            delete [] board[i];
        delete [] board;
    }

    void setID(unsigned int id);
    unsigned int getID();

    void addPlayer(const Player&, const SnakeHead&);
    const SnakeHead& getPlayer(const Player&) const;
    void updatePlayer(const Player&, const SnakeHead&);
    void removePlayer(const Player&);

    void addEvent(const Event& event);

    bool checkBoard(int x, int y) const;
    void updateBoard(int x, int y, bool b);

    unsigned int getWidth();
    unsigned int getHeight();

private:
    unsigned int gameID; // as in server datagram
    std::map<Player, SnakeHead> playerHeads;
    std::vector<Event> eventHistory;
    GameBoard board;
    unsigned int boardWidth; // game board width in px dft 800
    unsigned int boardHeight; // game board height in px dft 600
};

#endif // SITACKA_GAMESTATE_H
