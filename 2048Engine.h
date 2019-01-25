#ifndef 2048Engine_h
#define 2048Engine_h

#include "Board.h"

class 2048Engine {
	public:
		2048Engine();

		bool beginningPhase();
		bool mainPhase();
		void endPhase();

		~2048Engine();

		bool game_state;
		uint8_t empty_sqrs_cnt;

	private:
		Board *brd;

};

#endif
