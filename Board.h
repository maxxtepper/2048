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
		void clearEmptySquaresList();

		void generateNewPiece();

		bool tryDirection(uint8_t,uint8_t,uint8_t);
		int getSquarePieceValue(int x,int y);
		int getRandomNumber(int);
		bool legalMoveState();

		std::vector<Square*> empty_sqrs;
		uint8_t empty_sqrs_cnt;
		UniformRandom *unirand;

  private:
    Square *sqr[4][4];
};

#endif
