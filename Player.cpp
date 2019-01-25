#include "Player.h"

Player::Player(int pId) {
  pId_ = pId;

  //  THIS ORDER MATTERS!!!
  for (int i=0; i<8; i++) {
    pc_[i] = new Pawn();
  }
  pc_[8]  = new Rook();
  pc_[9] = new Knight();
  pc_[10] = new Bishop();
  pc_[11] = new Queen();
  pc_[12] = new King();
  pc_[13] = new Bishop();
  pc_[14] = new Knight();
  pc_[15] = new Rook();
}

Player::~Player() {
  for (int i=0; i<16; i++) {
    delete pc_[i];
  }
}

int Player::getPid() {
  return pId_;
}
