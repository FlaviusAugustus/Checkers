#pragma once
#include <stdio.h>
#include "SDL.h"
#include "SDL_main.h"
#include "Constants.h"
#include "Sprite.h"
#include "RGB.h"



class UserInterface {

	char buffer[MaxBufferSize];
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
	const Uint8* keyState;

public:

	SDL_Texture* charSet;

	SDL_Event event;

	UserInterface();

	~UserInterface();

	bool loadTexture(const char* path, SDL_Texture** texture);

	bool init();

	void DrawTexture(Sprite sprite);

	void DrawPixel(int x, int y, colorRGB color);

	void DrawLine(int x1, int y1, int x2, int y2, colorRGB color);

	void DrawRectangle(int x, int y, int l, int k, colorRGB out, colorRGB in);

	void quit(SDL_Window** window, SDL_Surface** surface);

	void DrawString(int x, int y, const char* text);

	void changeBackgroundColor();

	void drawScene();

	void drawBoard();

	void clearScreen();

	const Uint8* getKeyboardState();

};