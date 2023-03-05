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


	for (int i = ScreenHeight - TileSize; i >= 0; i -= TileSize) {
		for(int j = 0; j < ScreenHeight; j += TileSize) {
		
			if(white & 1) {
			
				currentColor = whiteColor;
				DrawRectangle(j + TileSize / 4, i + TileSize / 4, TileSize/2, TileSize/2, currentColor, currentColor);

			}

			if(black & 1) {
			
				currentColor = blackColor;
				DrawRectangle(j + TileSize/4, i + TileSize / 4, TileSize/2, TileSize/2, currentColor, currentColor);
			
			}

			white >>= 1;
			black >>= 1;

		}
	
	}

	drawScene();

}

void CheckersUI::drawLegalMoves(Bitboard legalMoves) {

	for (int i = ScreenHeight - TileSize; i >= 0; i -= TileSize) {
		for (int j = 0; j < ScreenHeight; j += TileSize) {

			if (legalMoves & 1) {

				DrawRectangle(j, i, TileSize, TileSize, highlightColor, highlightColor);

			}

			legalMoves >>= 1;
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