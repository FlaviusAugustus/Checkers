#pragma once
#include "Lookups.h"
typedef unsigned long long Bitboard;

class Board {

	Lookups lookups;

	public:

	Bitboard allPieces;
	Bitboard whitePieces;
	Bitboard blackPieces;
	
	Board();

	Bitboard calculateLegalMoves(int pos, int round);

	bool movePiece(int startPos, int endPos, int round);

	bool isCurrent(int pos, int round);
};