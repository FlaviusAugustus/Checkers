#include "Board.h"


Board::Board() {

	whitePieces = lookups.Mask1 | lookups.Mask2 | lookups.Mask3;
	blackPieces = lookups.Mask6 | lookups.Mask7 | lookups.Mask8;

	allPieces = whitePieces | blackPieces;

}

void Board::movePiece(int posStart, int posEnd) {

	allPieces ^= lookups.Piecies[posStart];
	allPieces |= lookups.Piecies[posEnd];
	  
}