#include "CheckersUI.h"
typedef unsigned long long Bitboard;


void CheckersUI::drawBoard(Bitboard white, Bitboard black) {

	colorRGB currentColor;

	for (int i = ScreenHeight - TileSize; i >= 0; i -= TileSize) {
		for (int j = 0; j < ScreenHeight; j += TileSize) {

			currentColor = ((i + j) / TileSize) % 2 ? ChessComGreen : ChessComCream;
			DrawRectangle(i, j, TileSize, TileSize, currentColor, currentColor);

		}

	}

	int shiftCount = 0;

	while(white || black) {

		if(white & 1) {
			
			currentColor = whiteColor;
			DrawRectangle(TileSize * (shiftCount % 8) + TileSize / 4, ScreenHeight - TileSize * (shiftCount / 8) - TileSize + TileSize / 4, TileSize / 2, TileSize / 2, currentColor, currentColor);

		}

		if(black & 1) {
			
			currentColor = blackColor;
			DrawRectangle(TileSize * (shiftCount % 8) + TileSize/4, ScreenHeight - TileSize * (shiftCount / 8) - TileSize + TileSize / 4, TileSize/2, TileSize/2, currentColor, currentColor);
			
		}

		shiftCount++;
		white >>= 1;
		black >>= 1;

	}
	
	drawScene();

}

void CheckersUI::drawLegalMoves(Bitboard legalMoves) {

	int shiftCount = 0;

	while(legalMoves >>= 1) {

		shiftCount++;
	
		if(legalMoves & 1) {
		
			DrawRectangle(TileSize * (shiftCount % 8), ScreenHeight - TileSize*(shiftCount/8) - TileSize, TileSize, TileSize, highlightColor, highlightColor);
		
		}
	
	}

	drawScene();

}

int CheckersUI::getMousePos() {

	int mouseX;
	int mouseY;

	SDL_GetMouseState(&mouseX, &mouseY);

	return mouseX / TileSize + (ScreenHeight - mouseY) / TileSize * 8;

}