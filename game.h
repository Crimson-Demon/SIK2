#ifndef SITACKA_GAME_H
#define SITACKA_GAME_H

#include "game_state.h"
#include "rng.h"

class Game {
public:
	void start();
    void computeRound();
    void finishGame();

private:
    GameState currentGameState;
};

#endif // SITACKA_GAME_H