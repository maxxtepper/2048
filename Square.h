#ifndef SQUARE_H
#define SQUARE_H

#include <stdint.h>
#include "Global.h"
#include "Piece.h"

class Square {
  public:
    Square(int,int);
    ~Square();
 
		void resetChangeState();
    Piece *getPiece() {return resident_pc;}
    void setPiece(Piece* pc) {resident_pc=pc;}
		void setNeighbor(int direction, Square *sqr);

		bool checkNeighborValue(int direction);
		bool checkNeighborMain(int direction);

		void createPiece(int rand_val);
		void destroyPiece();

    Piece *resident_pc;

		Square *neighbor_sqr[4];

  private:
    int x_;
    int y_;
};

#endif
