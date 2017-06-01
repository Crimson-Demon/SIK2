#include "server.h"
#include <getopt.h>

void Server::startGame() {
    currentGameState.setID(rng.rand());
    generateEvent(EventType::NEW_GAME);
    for(int i = 0; i < currentPlayers.size(); i++) {
        double snakeHeadX = (rng.rand() % currentGameState.getWidth()) + 0.5;
        double snakeHeadY = (rng.rand() % currentGameState.getWidth()) + 0.5;

        unsigned int direction  = rng.rand() % 360;
        if(currentGameState.checkBoard(snakeHeadX, snakeHeadY))
            generateEvent(EventType::PLAYER_ELIMINATED);
        else {

            generateEvent(EventType::PIXEL);
        }
    }
}

void Server::computeGameRound() {

}

void Server::finishGame() {

}

int main(int argc, char* argv[]) {
    // parse arguments
    // create server
    Server server = Server();
    // wait for players
    // while broadcasting
}