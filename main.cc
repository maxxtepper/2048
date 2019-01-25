#include <iostream>
#include <string>
#include <random>
#include "Global.h"
#include "Engine2048.h"

int chooseDirection();

int main() {
	//////////////////////////////////////////////////////
	////		Create the 2048 Engine
	//////////////////////////////////////////////////////
	Engine2048 *engine2048;
	engine2048 = new Engine2048();

	//////////////////////////////////////////////////////
	////		Start the Game
	//////////////////////////////////////////////////////
	bool game_state;
	uint8_t direction;
	bool input_success=false;
	std::string input;
	while (game_state) {
		engine2048->printBoard();
		game_state = engine2048->beginningPhase();
		if (game_state) {
			input_success = false;
			while (!input_success) {
				//direction   = cntrlr->getDirection();
				std::cout << "Enter next move: ";
				while (!input_success) {
					input_success = true;
					std::cin >> input;
					std::cout << std::endl;
					if (input == "w") direction = UP;
					else if (input == "s") direction = DOWN;
					else if (input == "a") direction = LEFT;
					else if (input == "d") direction = RIGHT;
					else {
						std::cout << "Try again: ";
						input_success = false;
					}
				}
				game_state = engine2048->mainPhase(direction);
			}
			engine2048->endPhase();
		} else {
			//	Game ends
			std::cout << "The Game Is Over.\n";
		}
	}
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

