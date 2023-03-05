#include "Board.h"
#include <stdio.h>

typedef unsigned long long Bitboard;

Board::Board() {

	whitePieces = lookups.Mask1 | lookups.Mask2 | lookups.Mask3;
	blackPieces = lookups.Mask6 | lookups.Mask7 | lookups.Mask8;

	allPieces = whitePieces | blackPieces;

}

bool Board::isCurrent(int pos, int round) {

	Bitboard& currentBitboard = round % 2 ? whitePieces : blackPieces;

	if (!(currentBitboard & lookups.Pieces[pos])) {

		return false;

	}

	return true;
}

Bitboard Board::calculateLegalMoves(int pos, int round) {

	if(!isCurrent(pos, round)) {
	
		return 0;
	
	}

	Bitboard pos1 = (lookups.Pieces[pos] & ~(lookups.Mask1 | lookups.MaskA)) >> 9;
	Bitboard pos2 = (lookups.Pieces[pos] & ~(lookups.Mask1 | lookups.MaskH)) >> 7;
	Bitboard pos3 = (lookups.Pieces[pos] & ~(lookups.Mask8 | lookups.MaskA)) << 7;
	Bitboard pos4 = (lookups.Pieces[pos] & ~(lookups.Mask8 | lookups.MaskH)) << 9;

	Bitboard legalMoves = pos1 | pos2 | pos3 | pos4;

	legalMoves &= ~allPieces;

	return legalMoves;
}

bool Board::movePiece(int posStart, int posEnd, int round) {

	Bitboard& currentBitboard = round % 2 ? whitePieces : blackPieces;

	if(posStart == posEnd || !isCurrent(posStart, round)) {

		return false;
	
	}

	Bitboard legalMoves = calculateLegalMoves(posStart, round);
	
	if(lookups.Pieces[posEnd] & legalMoves) {
	
		currentBitboard ^= lookups.Pieces[posStart];
		currentBitboard |= lookups.Pieces[posEnd] & legalMoves;
	
	}

	allPieces = whitePieces | blackPieces;
	
	return true;
}