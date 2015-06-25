#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL2/SDL.h>
#include <stdio.h>

class GameWindow
{
public:
	GameWindow(void);
	~GameWindow(void);
	bool init(void);
	bool loadMedia();
	void close(void);
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Window* window;
	SDL_Surface* buffer1;
	SDL_Surface* buffer2;
};

#endif //GAME_WINDOW_H
