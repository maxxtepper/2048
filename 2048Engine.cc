#include "2048Engine.h"

2048Engine::2048Engine() {
	//	Make the board
	brd = new Board();

	//	Make the random number generator
	unirand = new UniformRandom();

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

2048Engine::~2048Engine() {
}

bool 2048Engine::beginningPhase() {
	//	Generate list of empty squares
	empty_sqrs_cnt = brd->generateEmptySquaresList();
	//	Generate random piece for random empty square
	brd->generateNewPiece();
	
	//	If no empty squares, check legal moves
	if (empty_sqrs_cnt == 0)
		game_state = brd->legalMoveState();

	return game_state;
}

bool 2048Engine::mainPhase(uint8_t direction) {
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
	return temp;
}

void 2048Engine::endPhase() {
	//	Clear list of empty squares
	
	//	Reset change states
	brd->resetChangeStates();
}
