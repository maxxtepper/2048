#ifndef Engine2048_H
#define Engine2048_H

#include <iostream>
#include <stdint.h>
#include "Board.h"
#include "Global.h"

class Engine2048 {
	public:
		Engine2048();

		bool beginningPhase();
		bool mainPhase(int);
		void endPhase();

		void printBoard();

		~Engine2048();

		bool game_state;


		void holdBoardState();
		bstate_t getHeldBoardState();

	private:
		Board *brd;
		bstate_t board_state;
};

#endif
