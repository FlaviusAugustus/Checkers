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

	void getAdjacentPiecies(Bitboard& pos1, Bitboard& pos2, Bitboard& pos3, Bitboard& pos4, int pos, int round);

	Bitboard calculateLegalMoves(int pos, int round);

	Bitboard calculateLegalAttacks(int pos, int round);

	Bitboard& getCurrent(int round);

	Bitboard& getNotCurrent(int round);

	bool movePiece(int startPos, int endPos, int round);

	bool isCurrent(int pos, int round);

	void reset();
};