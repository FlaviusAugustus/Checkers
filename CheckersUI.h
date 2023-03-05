#pragma once
#include "UserInterface.h"
typedef unsigned long long Bitboard;

class CheckersUI : public UserInterface {

	public:

	void drawBoard(Bitboard white, Bitboard black);

	void drawLegalMoves(Bitboard legalMoves);

	int getMousePos();

};
