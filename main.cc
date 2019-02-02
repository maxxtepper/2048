#include <iostream>
#include <string>
#include <fstream>
#include "Global.h"
#include "Engine2048.h"

int chooseDirection();

int main() {
	//////////////////////////////////////////////////////
	////		Create the output data file
	//////////////////////////////////////////////////////
	std::fstream fout;
	fout.open ("test.txt",std::fstream::out);

	//////////////////////////////////////////////////////
	////		Create the 2048 Engine
	//////////////////////////////////////////////////////
	std::cout << "Starting engine...\n";
	Engine2048 *engine2048;
	engine2048 = new Engine2048();
	std::cout << "engine SUCCESS\n";

	//////////////////////////////////////////////////////
	////		Start the Game
	//////////////////////////////////////////////////////
	bstate_t board_state;
	bool game_state=false;
	int direction;
	bool dir_success=false;
	std::string input;
	while (!game_state) {
		game_state = engine2048->beginningPhase();
		engine2048->printBoard();
		engine2048->holdBoardState();
		if (!game_state) {
			dir_success = false;
			while (!dir_success) {
				direction = chooseDirection();
				dir_success = engine2048->mainPhase(direction);
			}
			board_state = engine2048->getHeldBoardState();

			//	Save the data
			for (int i=0; i<16; i++)
				fout << board_state.sqr_val[i] << ",";
			fout << direction << std::endl;

			engine2048->endPhase();
		} else {
			//	Game ends
		}
	}
	delete engine2048;
	fout.close();
	return 0;
}

int chooseDirection() {
	char direction[1];
	std::cin >> direction[0];
	switch(direction[0]) {
		case 'w':
			return UP;
		case 's':
			return DOWN;
		case 'a':
			return LEFT;
		case 'd':
			return RIGHT;
	}
	return 0;
}

