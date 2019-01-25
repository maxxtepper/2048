#include "Piece.h"

Piece::Piece() {
	changed = false;
}

Piece::~Piece() {
}

void Piece::incrimentValue() {
	resident_value = resident_value << 1;
	changed = true;
}

void Piece::resetTurn() {
	changed = false;
}

bool Piece::getChangeState() {
	return changed;
}

int Piece::getValue() {
	return resident_value;
}
