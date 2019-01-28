#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "Global.h"
#include "Square.h"
#include "UniformRandom.h"

class Board {
  public:
    Board();
    ~Board();
		void resetChangeStates();
		int generateEmptySquaresList();

		void generateNewPiece();

		bool tryDirection(int,int,int);
		int getSquarePieceValue(int x,int y);
		int getRandomNumber(int);
		bool legalMoveState();

		std::vector<Square*> empty_sqrs;
		int empty_sqrs_cnt;
		UniformRandom *unirand;

  private:
    Square *sqr[4][4];
};

#endif
