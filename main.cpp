#include <iostream>
#include <SDL.h>
#include "UserInterface.h"
#undef main



int main() {

	bool isRunning = true;
	UserInterface ui;

	if (!ui.init()) {

		return 1;
	}

	while (isRunning) {

		while (SDL_PollEvent(&ui.event)) {
			if (ui.event.type == SDL_QUIT) {
				isRunning = false;
			}
		}
		
		ui.drawBoard();

	
	}

	return 0;
}