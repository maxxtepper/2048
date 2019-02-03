#ifndef Engine2048_H
#define Engine2048_H

#include <iostream>
#include <iomanip>
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
		int *getHeldBoardState();

	private:
		Board *brd;
		int *gcycle;
		int game_cycle[16];
};

#endif
