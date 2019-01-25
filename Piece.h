#ifndef PIECE_H
#define PIECE_H

#include "Global.h"

class Piece {
  public:
    Piece();
    ~Piece();

		void incrimentValue();
		void setValue(int value) {resident_value = value;}
		void resetTurn();
		bool getChangeState();
		int getValue();

		int resident_value;
		bool changed;
  private:
};

#endif
