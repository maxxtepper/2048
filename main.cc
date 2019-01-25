#include <iostream>
#include <random>
#include "Global.h"
#include "2048Engine.h"

int chooseDirection();
void printBoard(Board *brd);

int main() {
	//////////////////////////////////////////////////////
	////		Create the 2048 Engine
	//////////////////////////////////////////////////////
	2048Engine *engine2048;
	engine2048 = new 2048Engine();
	
	//////////////////////////////////////////////////////
	////		Start the Game
	//////////////////////////////////////////////////////
	bool game_state;
	uint8_t direction;
	bool dir_success;
	while (game_state) {
		printBoard(brd);
		game_state = engine2048->beginningPhase();
		if (game_state) {
			while (!dir_success) {
				direction   = cntrlr->getDirection();
				dir_success = engine2048->mainPhase(direction);
			}
			engine2048->endPhase();
		} else {
			//	Game ends
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

void printBoard(Board *brd) {
	for (int y=3; y>=0; y--) {
		std::cout << "----------------------------------\n";
		std::cout << "|  ";
		for (int x=0; x<4; x++) {
			int value;
			value = brd->getSquarePieceValue(x,y);
			if (value) std::cout << value;
			else std::cout << "  ";
			if (x<3) std::cout << "  |  ";
			else std::cout << "  |" << std::endl;
		}
	}
	std::cout << "----------------------------------\n";
}
