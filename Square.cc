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

bool Square::checkNeighborValue(int direction) {
	if (neighbor_sqr[direction]) {
		Piece *neighbor_pc;
		neighbor_pc = neighbor_sqr[direction]->getPiece();
		int neighbor_val = neighbor_pc->getValue();
		int resident_val = resident_pc->getValue();
		if (neighbor_val==resident_val)
			return true;
		else
			return false;
	} else {
		return false;
	}
}

bool Square::checkNeighborMain(int direction) {
	bool success = false;
	//	First check to see if neighbor is null
	if (neighbor_sqr[direction]) {
		if (resident_pc) {
			Piece *neighbor_pc;
			neighbor_pc = neighbor_sqr[direction]->getPiece();
			if (!neighbor_pc) {
				//	If the neighbor square is empty
				neighbor_sqr[direction]->setPiece(resident_pc);
				resident_pc = NULL;
				success = true;
			} else {
				bool neighbor_chng, resident_chng;
				neighbor_chng = neighbor_pc->getChangeState();
				resident_chng = resident_pc->getChangeState();
				if (!resident_chng && !neighbor_chng) {
					//	If they pieces have not been combined yet
					int neighbor_val = neighbor_pc->getValue();
					int resident_val = resident_pc->getValue();
					if (neighbor_val==resident_val) {
						//	If the values are the same
						destroyPiece();
						neighbor_pc->incrimentValue();
						success = true;
					} else {
						//	The resident and neighbor cannot combine
						success = false;
					}
				} else {
					//	The resident and/or neighbor have already combined
					success = false;
				}
			}
		} else {
			//	There is no resident piece
			success = false;
		}
	} else {
		//	The neighbor square is null
		success = false;
	}
	return success;
}

void Square::createPiece(int rand_val) {
	resident_pc = new Piece();
	resident_pc->setValue(rand_val);
}

void Square::destroyPiece() {
	delete resident_pc;
	resident_pc = NULL;
}
