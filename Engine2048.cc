#include "Engine2048.h"

Engine2048::Engine2048() {
	//	Make the board
	brd = new Board();

	//	Game state variables
	game_state = false;
	empty_sqrs_cnt = 0;

	//	Setup the board
	//	Generate list of empty squares
	empty_sqrs_cnt = brd->generateEmptySquaresList();
	//	First starting piece
	brd->generateNewPiece();
	//	Second starting piece
	brd->generateNewPiece();
	
}

Engine2048::~Engine2048() {
}

bool Engine2048::beginningPhase() {
	//	Generate list of empty squares
	empty_sqrs_cnt = brd->generateEmptySquaresList();
	//	Generate random piece for random empty square
	brd->generateNewPiece();
	
	//	If no empty squares, check legal moves
	if (empty_sqrs_cnt == 0)
		game_state = brd->legalMoveState();

	return game_state;
}

bool Engine2048::mainPhase(uint8_t direction) {
	bool dir_success, temp;
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
	//	Clear list of empty squares
	
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
