#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "CheckersUI.h"
#include "Board.h"



int main(int argv, char** args) {

	bool isRunning = true;
	CheckersUI ui;
	Board board;

	int posS = -1;
	int posE;
	int round = 0;

	if (!ui.init()) {

		return 1;
	}
	
	ui.drawBoard(board.whitePieces, board.blackPieces);

	while (isRunning) {

		while (SDL_PollEvent(&ui.event)) {
			if (ui.event.type == SDL_QUIT) {
				isRunning = false;
			}

			if(ui.event.type == SDL_MOUSEBUTTONDOWN) {

				posS = ui.getMousePos();
				ui.drawLegalMoves(board.calculateLegalMoves(posS, round));
			}

			if(ui.event.type == SDL_MOUSEBUTTONUP) {

				if(board.movePiece(posS, ui.getMousePos(), round)) {
				
					round++;

				}

				ui.drawBoard(board.whitePieces, board.blackPieces);

			}
		}

		
	}

	return 0;
}