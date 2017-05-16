#ifndef SITACKA_SERVER_H
#define SITACKA_SERVER_H

class Server {
	unsigned int boardWidth; // game board width in px dft 800
	unsigned int boardHeight; // game board height in px dft 600
	unsigned int port; // port num dft 12345
	unsigned int roundsPerSec; // rounds per sec dft ROUNDS_PER_SEC 50
	unsigned int turningSpeed; // turning speed dft TURNING_SPEED 6
public:
	void parseInputArgs(int argc, char* argv[]); // uses getopt

private:

}

#endif // SITACKA_SERVER_H