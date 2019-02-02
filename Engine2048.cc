#include "Engine2048.h"

Engine2048::Engine2048() {
	//	Make the board
	brd = new Board();

	//	Game state variables
	game_state = false;

	//	Setup the board
	//	First starting piece
	brd->generateEmptySquaresList();
	brd->generateNewPiece();
}

Engine2048::~Engine2048() {
	delete brd;
}

bool Engine2048::beginningPhase() {
	//	Generate list of empty squares
	brd->generateEmptySquaresList();
	//	Generate random piece for random empty square
	brd->generateNewPiece();

	//	Check for a gameover
	game_state = !(brd->legalMoveState());

	return game_state;
}

bool Engine2048::mainPhase(int direction) {
	bool temp = false;
	bool dir_success = false;
	//	Try to slide the pieces
	switch(direction) {
		case UP:
			for (int iter=2; iter>=0; iter--)
				for (int y=iter; y<3; y++)
					for (int x=0; x<4; x++) {
						temp = brd->tryDirection(x,y,direction);
						if (temp) dir_success = temp;
					}
			break;
		case DOWN:
			for (int iter=1; iter<4; iter++)
				for (int y=iter; y>0; y--)
					for (int x=0; x<4; x++) {
						temp = brd->tryDirection(x,y,direction);
						if (temp) dir_success = temp;
					}
			break;
		case LEFT:
			for (int iter=1; iter<4; iter++)
				for (int x=iter; x>0; x--)
					for (int y=0; y<4; y++) {
						temp = brd->tryDirection(x,y,direction);
						if (temp) dir_success = temp;
					}
			break;
		case RIGHT:
			for (int iter=2; iter>=0; iter--)
				for (int x=iter; x<3; x++)
					for (int y=0; y<4; y++) {
						temp = brd->tryDirection(x,y,direction);
						if (temp) dir_success = temp;
					}
			break;
	}
	return dir_success;
}

void Engine2048::endPhase() {
	//	Reset change states
	brd->resetChangeStates();
}

void Engine2048::printBoard() {
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

void Engine2048::holdBoardState() {
	int count=0;
	for (int y=3; y>=0; y--) {
		for (int x=0; x<4; x++) {
			board_state.sqr_val[count]=brd->getSquarePieceValue(x,y);
			count++;
		}
	}
}

bstate_t Engine2048::getHeldBoardState() {
	return board_state;
}


