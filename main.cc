#include <iostream>
#include <string>
#include "Global.h"
#include "Engine2048.h"

int chooseDirection();

int main() {
	//////////////////////////////////////////////////////
	////		Create the 2048 Engine
	//////////////////////////////////////////////////////
	std::cout << "Starting engine...\n";
	Engine2048 *engine2048;
	engine2048 = new Engine2048();
	std::cout << "engin SUCCESS\n";

	//////////////////////////////////////////////////////
	////		Start the Game
	//////////////////////////////////////////////////////
	bool game_state=false;
	int direction;
	bool dir_success=false;
	std::string input;
	while (!game_state) {
		game_state = engine2048->beginningPhase();
		engine2048->printBoard();
		if (!game_state) {
			dir_success = false;
			while (!dir_success) {
				direction = chooseDirection();
				dir_success = engine2048->mainPhase(direction);
			}
			std::cout << "Ending...\n";
			engine2048->endPhase();
			std::cout << "Done!\n";
		} else {
			//	Game ends
			std::cout << "The Game Is Over.\n";
		}
	}
	delete engine2048;
	return 0;
}

int chooseDirection() {
	char direction[1];
	std::cout << "Choose a direction: ";
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

