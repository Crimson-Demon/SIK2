#ifndef SITACKA_PLAYER_H
#define SITACKA_PLAYER_H

class Player {
public:
	Player(std::uint64_t sessionID, char* name);
	~Player() { }

private:
	std::uint64_t sessionID;
    char name[65];
};

#endif // SITACKA_PLAYER_H