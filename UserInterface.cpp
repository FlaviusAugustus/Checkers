#define _CRT_SECURE_NO_WARNINGS
#include "SDL.h"
#include "SDL_main.h"
#include "UserInterface.h"
#include "Constants.h"
#include "Sprite.h"


UserInterface::UserInterface() {

	window = nullptr;
	screenSurface = nullptr;
	renderer = nullptr;
	charSet = nullptr;
	keyState = SDL_GetKeyboardState(NULL);

}

UserInterface::~UserInterface() {

	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
	
}

bool UserInterface::loadTexture(const char* path, SDL_Texture** texture) {

	SDL_Surface* image = SDL_LoadBMP(path);

	if (!image)
	{
		return false;
	}

	*texture = SDL_CreateTextureFromSurface(renderer, image);

	if (!*texture)
	{
		return false;
	}

	SDL_FreeSurface(image);

	return true;
}

bool UserInterface::init()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		return false;

	}
	else {

		SDL_CreateWindowAndRenderer(ScreenWidth, ScreenHeight, 0, &window, &renderer);

		if (window == nullptr || renderer == nullptr) {

			return false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}

	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
	SDL_RenderSetLogicalSize(renderer, ScreenWidth, ScreenHeight);
	SDL_SetWindowTitle(window, "Grzech Gracjan 193579");

	return true;

}

void UserInterface::DrawTexture(Sprite sprite) {

	SDL_RenderCopy(renderer, sprite.texture, NULL, &sprite.textureRect);

}

void UserInterface::DrawPixel(int x, int y, colorRGB color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
	SDL_RenderDrawPoint(renderer, x, y);
}

void UserInterface::DrawLine(int x1, int y1, int x2, int y2, colorRGB color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void UserInterface::DrawRectangle(int x, int y, int l, int k, colorRGB out, colorRGB in) {

	SDL_Rect rectFill = { x, y, l, k };

	SDL_SetRenderDrawColor(renderer, out.r, out.g, out.b, 0);
	SDL_RenderDrawRect(renderer, &rectFill);

	rectFill.x++;
	rectFill.y++;
	rectFill.w -= 2;
	rectFill.h -= 2;

	SDL_SetRenderDrawColor(renderer, in.r, in.g, in.b, 0);
	SDL_RenderFillRect(renderer, &rectFill);
}

void UserInterface::quit(SDL_Window** window, SDL_Surface** surface) {
	SDL_FreeSurface(*surface);
	*surface = nullptr;

	SDL_DestroyWindow(*window);
	*window = nullptr;

	SDL_Quit();
}

void UserInterface::DrawString(int x, int y, const char* text) {
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_RenderCopy(renderer, charSet, &s, &d);
		x += 8;
		text++;
	}
}

void UserInterface::changeBackgroundColor() {

	SDL_SetRenderDrawColor(renderer, 0, 150, 0, 0);
}

void UserInterface::drawScene() {

	SDL_RenderPresent(renderer);
}

void UserInterface::clearScreen() {

	SDL_RenderClear(renderer);
}

const Uint8* UserInterface::getKeyboardState() {

	SDL_PumpEvents();
	return keyState;

}

void UserInterface::drawBoard() {

	colorRGB currentColor;

	for (int i = 0; i < ScreenWidth; i += TileSize) {
		for (int j = 0; j < ScreenHeight; j += TileSize) {

			currentColor = ((i + j) / TileSize) % 2 ? ChessComGreen : ChessComCream;
			DrawRectangle(i, j, TileSize, TileSize, currentColor, currentColor);

		}

	}

	drawScene();

}