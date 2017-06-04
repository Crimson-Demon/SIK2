#ifndef SITACKA_SERVER_H
#define SITACKA_SERVER_H

#define DFT_BOARD_WIDTH 800
#define DFT_BOARD_HEIGHT 600
#define DFT_PORT 12345
#define DFT_ROUNDS_PER_SEC 50
#define DFT_TURNING_SPEED 6

#include "../game_state.h"
#include "../rng.h"
#include <vector>

class Server {

public:

	Server(unsigned int boardWidth = DFT_BOARD_WIDTH,
           unsigned int boardHeight = DFT_BOARD_HEIGHT,
           unsigned int port = DFT_PORT,
           unsigned int roundsPerSec = DFT_ROUNDS_PER_SEC,
           unsigned int turningSpeed = DFT_TURNING_SPEED,
           unsigned int seed
    ) : port(port), roundsPerSec(roundsPerSec), turningSpeed(turningSpeed), rng(dynamic_cast<uint64_t >(seed))
    { currentGameState = GameState(static_cast<unsigned int>(rng.rand()), boardWidth, boardHeight); }

    void startGame();
    void computeGameRound();
    void finishGame();
    void generateEvent(EventType eventType);
    void waitForPlayersToStart();

private:
	unsigned int port; // port num dft 12345
	unsigned int roundsPerSec; // rounds per sec dft ROUNDS_PER_SEC 50
	unsigned int turningSpeed; // turning speed dft TURNING_SPEED 6
    GameState currentGameState;
    std::vector<Player> currentPlayers;
    RNG rng;

};

#endif // SITACKA_SERVER_H