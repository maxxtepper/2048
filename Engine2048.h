#ifndef Engine2048_H
#define Engine2048_H

#include <iostream>
#include <stdint.h>
#include "Board.h"

class Engine2048 {
	public:
		Engine2048();

		bool beginningPhase();
		bool mainPhase(int);
		void endPhase();

		void printBoard();

		~Engine2048();

		bool game_state;
		int empty_sqrs_cnt;

	private:
		Board *brd;
};

#endif
