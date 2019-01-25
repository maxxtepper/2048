#include <iostream>
#include "Board.h"

Board::Board() {
	//	Create the squares
  for (int x=0; x<4; x++)
    for (int y=0; y<4; y++)
      sqr[x][y] = new Square(x,y);

	//	Setup the neighbors
  for (int x=0; x<4; x++) {
    for (int y=0; y<4; y++) {
			if (x==0) {
				sqr[x][y]->setNeighbor(LEFT,NULL);
				sqr[x][y]->setNeighbor(RIGHT,sqr[x+1][y]);
			} else if (x==3) {
				sqr[x][y]->setNeighbor(LEFT,sqr[x-1][y]);
				sqr[x][y]->setNeighbor(RIGHT,NULL);
			}
			if (y==0) {
				sqr[x][y]->setNeighbor(DOWN,NULL);
				sqr[x][y]->setNeighbor(UP,sqr[x][y+1]);
			} else if (y==3) {
				sqr[x][y]->setNeighbor(DOWN,sqr[x][y-1]);
				sqr[x][y]->setNeighbor(UP,NULL);
			}
			if (x > 0 && x < 3) {
				sqr[x][y]->setNeighbor(LEFT,sqr[x-1][y]);
				sqr[x][y]->setNeighbor(RIGHT,sqr[x+1][y]);
			}
			if (y > 0 && y < 3) {
				sqr[x][y]->setNeighbor(DOWN,sqr[x][y-1]);
				sqr[x][y]->setNeighbor(UP,sqr[x][y+1]);
			}
		}
	}

	//	Make the random number generator
	unirand = new UniformRandom();
}

Board::~Board() {
  for (int x=0; x<4; x++) {
    for (int y=0; y<4; y++) {
      delete sqr[x][y];
    }
  }
	delete unirand;
}

void Board::resetChangeStates() {
	for (int x=0; x<4; x++)
		for (int y=0; y<4; y++)
			sqr[x][y]->resetChangeState();
}

int Board::generateEmptySquaresList() {
	empty_sqrs_cnt = 0;
	Piece *pc;
	for (int x=0; x<4; x++)
		for (int y=0; y<4; y++) {
			pc = sqr[x][y]->getPiece();
			if (!pc) {
				empty_sqrs_cnt++;
				empty_sqrs.push_back(sqr[x][y]);
			}
		}
	return empty_sqrs_cnt;
}

void Board::clearEmptySquaresList() {
	empty_sqrs.clear();
}

bool Board::legalMoveState() {
	//	If false, gameover!
	if (empty_sqrs_cnt == 0) {
		//	Have all squares check neighbors
		//	for pieces with like values
		bool legal_up, legal_right;
		for (int x=0; x<4; x++) {
			for (int y=0; y<4; y++) {
				legal_up = sqr[x][y]->checkNeighborValue(UP);
				legal_right = sqr[x][y]->checkNeighborValue(RIGHT);
				if (legal_up || legal_right)
					return true;
			}
		}
		return false;
	} else
		return true;
}

void Board::generateNewPiece() {
	//	Generate random piece for random empty square
	int rand_sqr, rand_val;
	std::cout << "Here\n";
	rand_sqr = unirand->drawNumber(0,empty_sqrs_cnt-1);
	std::cout << "Here\n";
	rand_val = unirand->drawNumber(0,100);
	std::cout << "Here\n";
	if (rand_val > 90)
		rand_val = 4;
	else
		rand_val = 2;
	std::cout << "Making the piece\n";
	empty_sqrs[rand_sqr]->createPiece(rand_val);
}

bool Board::tryDirection(uint8_t x, uint8_t y, uint8_t  direction) {
	bool check_state;
	check_state = sqr[x][y]->checkNeighborMain(direction);
	return check_state;
}

int Board::getSquarePieceValue(int x, int y) {
	Piece *pc;
	pc = sqr[x][y]->getPiece();
	if (pc)
		return pc->getValue();
	else
		return 0;
}
