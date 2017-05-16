#ifndef SITACKA_SERVER_H
#define SITACKA_SERVER_H

class Server {
	int boardWidth; // game board width in px dft 800
	int boardHeight; // game board height in px dft 600
	int port; // port num dft 12345
	int rps; // rounds per sec dft ROUNDS_PER_SEC 50
	int ts; // turning speed dft TURNING_SPEED 6
public:
	void parseInputArgs(int argc, char* argv[]); // uses getopt

private:

}

#endif // SITACKA_SERVER_H