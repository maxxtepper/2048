#include <iostream>
#include <string.h>
#include "Square.h"

Square::Square(int x, int y) {
  x_ = x;
  y_ = y;
	resident_pc = NULL;
}

Square::~Square() {
}

void Square::resetChangeState() {
	if (resident_pc)
		resident_pc->resetTurn();
}

void Square::setNeighbor(int direction, Square *sqr) {
	neighbor_sqr[direction] = sqr;
}

bool Square::checkNeighborPiece(int direction) {
	Piece *neighbor_pc;
	neighbor_pc = neighbor_sqr[direction]->getPiece();
	if (neighbor_pc)
		return true;
	else
		return false;
}

bool Square::checkNeighborValue(int direction) {
	Piece *neighbor_pc;
	neighbor_pc = neighbor_sqr[direction]->getPiece();
	if (!neighbor_pc)
		return false;
	else {
		int neighbor_value, resident_value;
		neighbor_value = neighbor_pc->getValue();
		resident_value = resident_pc->getValue();
		if (resident_value == neighbor_value)
			return true;
		else 
			return false;
	}
}

bool Square::checkNeighborChange(int direction) {
	Piece *neighbor_pc;
	neighbor_pc = neighbor_sqr[direction]->getPiece();
	bool neighbor_chng, resident_chng;
	neighbor_chng = neighbor_pc->getChangeState();
	resident_chng = resident_pc->getChangeState();
	if (!resident_chng && !neighbor_chng)
		// finish this
		// also, make sure that the changeState
		// is only called when pieces combine,
		// and not when pieces slide into an empty
		// square.
				destroyPiece();
				neighbor_pc->incrimentValue();
				success = true;
			}
		} else {
			neighbor_sqr[direction]->setPiece(resident_pc);
			resident_pc = NULL;
			success = true;
		}
	} 
	return success;
}

void Square::createPiece(uint8_t rand_val) {
	resident_pc = new Piece();
	resident_pc->setValue(rand_val);
}

void Square::destroyPiece() {
	delete resident_pc;
	resident_pc = NULL;
}
