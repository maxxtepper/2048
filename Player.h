#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"

class Player {
  public:
    Player(int);
    ~Player();

    int getPid();
    Piece *getPiece(int pNum) {return pc_[pNum];}

  private:
    Piece *pc_[16];
    int pId_;
};

#endif
