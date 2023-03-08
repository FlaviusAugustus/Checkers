#include "Board.h"
#include <stdio.h>

typedef unsigned long long Bitboard;

Board::Board() {
	
	reset();

}

void Board::reset() {

	whitePieces = lookups.Mask1 | lookups.Mask2 | lookups.Mask3;
	blackPieces = lookups.Mask6 | lookups.Mask7 | lookups.Mask8;

	allPieces = whitePieces | blackPieces;

}


Bitboard& Board::getCurrent(int round) {

	return 	round % 2 ? whitePieces : blackPieces;

}

Bitboard& Board::getNotCurrent(int round) {

	return !(round % 2) ? whitePieces : blackPieces;

}

bool Board::isCurrent(int pos, int round) {

	Bitboard& currentBitboard = getCurrent(round);

	if (!(currentBitboard & lookups.Pieces[pos])) {

		return false;

	}

	return true;
}

void Board::getAdjacentPiecies(Bitboard& pos1, Bitboard& pos2, Bitboard& pos3, Bitboard& pos4, int pos, int round) {

	Bitboard& current = getCurrent(round);

	pos1 = (lookups.Pieces[pos] & ~(lookups.Mask1 | lookups.MaskA)) >> 9;
	pos2 = (lookups.Pieces[pos] & ~(lookups.Mask1 | lookups.MaskH)) >> 7;
	pos3 = (lookups.Pieces[pos] & ~(lookups.Mask8 | lookups.MaskA)) << 7;
	pos4 = (lookups.Pieces[pos] & ~(lookups.Mask8 | lookups.MaskH)) << 9;

	pos1 &= ~current;
	pos2 &= ~current;
	pos3 &= ~current;
	pos4 &= ~current;

}

Bitboard Board::calculateLegalAttacks(int pos, int round) {

	if (!isCurrent(pos, round)) {

		return 0;

	}

	Bitboard legalAttacks = 0;

	Bitboard& notCurrent = getNotCurrent(round);
	Bitboard& current = getCurrent(round);

	Bitboard pos1;
	Bitboard pos2;
	Bitboard pos3;
	Bitboard pos4;

	getAdjacentPiecies(pos1, pos2, pos3, pos4, pos, round);

	if (pos1 & notCurrent) { pos1 = ((pos1 & ~(lookups.Mask1 | lookups.MaskA)) >> 9) & ~allPieces; legalAttacks |= pos1; }
	if (pos2 & notCurrent) { pos2 = ((pos2 & ~(lookups.Mask1 | lookups.MaskH)) >> 7) & ~allPieces; legalAttacks |= pos2; }
	if (pos3 & notCurrent) { pos3 = ((pos3 & ~(lookups.Mask8 | lookups.MaskA)) << 7) & ~allPieces; legalAttacks |= pos3; }
	if (pos4 & notCurrent) { pos4 = ((pos4 & ~(lookups.Mask8 | lookups.MaskH)) << 9) & ~allPieces; legalAttacks |= pos4; }

	return legalAttacks;

}

Bitboard Board::calculateLegalMoves(int pos, int round) {

	if(!isCurrent(pos, round)) {
	
		return 0;
	
	}

	Bitboard& notCurrent = getNotCurrent(round);
	Bitboard& current = getCurrent(round);

	Bitboard pos1;
	Bitboard pos2;
	Bitboard pos3;
	Bitboard pos4;

	getAdjacentPiecies(pos1, pos2, pos3, pos4, pos, round);

	if (pos1 & notCurrent) { pos1 = ((pos1 & ~(lookups.Mask1 | lookups.MaskA)) >> 9) & ~allPieces; }
	if (pos2 & notCurrent) { pos2 = ((pos2 & ~(lookups.Mask1 | lookups.MaskH)) >> 7) & ~allPieces; }
	if (pos3 & notCurrent) { pos3 = ((pos3 & ~(lookups.Mask8 | lookups.MaskA)) << 7) & ~allPieces; }
	if (pos4 & notCurrent) { pos4 = ((pos4 & ~(lookups.Mask8 | lookups.MaskH)) << 9) & ~allPieces; }

	Bitboard legalMoves = pos1 | pos2 | pos3 | pos4;

	return legalMoves;

}

bool Board::movePiece(const int posStart, int posEnd, int round) {

	Bitboard& currentBitboard = getCurrent(round);
	Bitboard& notCurrent = getNotCurrent(round);

	Bitboard legalMoves = calculateLegalAttacks(posStart, round) & ~calculateLegalMoves(posStart, round);
	
	if(isCurrent(posStart, round) && lookups.Pieces[posEnd] & legalMoves) {

		currentBitboard ^= lookups.Pieces[posStart];
		currentBitboard |= lookups.Pieces[posEnd] & legalMoves;

		bool attacked = false;

		if ((posStart - 18) == posEnd) { notCurrent ^= lookups.Pieces[posStart - 9]; attacked = true; }
		else if ((posStart - 14) == posEnd) { notCurrent ^= lookups.Pieces[posStart - 7]; attacked = true; }
		else if ((posStart + 18) == posEnd) { notCurrent ^= lookups.Pieces[posStart + 9]; attacked = true; }
		else if ((posStart + 14) == posEnd) { notCurrent ^= lookups.Pieces[posStart + 7]; attacked = true; }
		
		allPieces = whitePieces | blackPieces;

		if(attacked && calculateLegalAttacks(posEnd, round)) {
		
			return false;

		}

		return true;
	
	}

	return false;

}

