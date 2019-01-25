#ifndef SQUARE_H
#define SQUARE_H

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

		bool checkNeighborPiece(int direction);
		bool checkNeighborValue(int direction);
		bool checkNeighborChange(int direction);

		void createPiece(uint8_t rand_val);
		void destroyPiece();

    Piece *resident_pc;

		Square *neighbor_sqr[4];

  private:
    int x_;
    int y_;
};

#endif
