#include "CheckersUI.h"
typedef unsigned long Bitboard;


void CheckersUI::drawBoard(Bitboard white, Bitboard black) {

	colorRGB currentColor;

	for (int i = 0; i < ScreenWidth; i += TileSize) {
		for (int j = 0; j < ScreenHeight; j += TileSize) {

			currentColor = ((i + j) / TileSize) % 2 ? ChessComGreen : ChessComCream;
			DrawRectangle(i, j, TileSize, TileSize, currentColor, currentColor);

		}

	}


	for (int i = 0; i < ScreenWidth; i += TileSize) {
		for(int j = i % (2*TileSize) ? 0 : TileSize; j < ScreenHeight; j += 2 * TileSize) {
		
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