#pragma once
#include <stdio.h>
#include "SDL.h"
#include "SDL_main.h"
#include <SDL_ttf.h>
#include "Constants.h"
#include "Sprite.h"
#include "RGB.h"



class UserInterface {

protected:

	char buffer[MaxBufferSize];
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
	TTF_Font* font;
	const Uint8* keyState;

public:

	SDL_Texture* charSet;

	SDL_Event event;

	UserInterface();

	~UserInterface();

	bool loadTexture(const char* path, SDL_Texture** texture);

	bool init();

	bool loadFromText(const char* text, colorRGB color);

	void DrawTexture(Sprite sprite);

	void DrawPixel(int x, int y, colorRGB color);

	void DrawLine(int x1, int y1, int x2, int y2, colorRGB color);

	void DrawRectangle(int x, int y, int l, int k, colorRGB out, colorRGB in);

	void quit(SDL_Window** window, SDL_Surface** surface);

	void DrawString(int x, int y, const char* text);

	void changeBackgroundColor();

	void drawScene();

	void clearScreen();

	const Uint8* getKeyboardState();

};