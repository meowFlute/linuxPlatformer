#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL.h>
#include <stdio.h>
#include <string>

#include "EventHandler.h"

class GameWindow
{
public:
	GameWindow(void);
	~GameWindow(void);
	bool init(void);
	bool loadMedia();
	void close(void);
	SDL_Surface* get_viewingScreen();
	SDL_Surface* get_imageBuffer();
	void set_imageBuffer(SDL_Surface* image);
	SDL_Window* get_window();
	EventHandler eventHandler;
private:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	SDL_Window* window;
	SDL_Surface* viewingScreen;
	SDL_Surface* imageBuffer;
};

#endif //GAME_WINDOW_H
