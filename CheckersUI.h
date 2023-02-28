#pragma once
#include "UserInterface.h"
typedef unsigned long Bitboard;

class CheckersUI : public UserInterface {

	public:

	void drawBoard(Bitboard white, Bitboard black);

};
