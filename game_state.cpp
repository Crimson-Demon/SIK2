#include "game_state.h"

void GameState::setID(unsigned int id) {
    gameID = id;
}

unsigned int GameState::getID() {
    return gameID;
}

void GameState::addPlayer(const Player& player, const SnakeHead& snakeHead) {
    if(playerHeads.find(player) == playerHeads.end())
        playerHeads[player] = snakeHead;
}

const SnakeHead& GameState::getPlayer(const Player& player) const {
    if(playerHeads.find(player) != playerHeads.end())
        return playerHeads[player];
    else
        return NULL;
}

void GameState::updatePlayer(const Player& player, const SnakeHead& snakeHead) {
    playerHeads[player] = snakeHead;
}

void GameState::removePlayer(const Player& player) {
    playerHeads.erase(player);
}

void GameState::addEvent(const Event& event) {
    eventHistory.push_back(event);
}

bool GameState::checkBoard(int x, int y) const {
    return board[x][y];
}

void GameState::updateBoard(int x, int y, bool b){
    board[x][y] = b;
}