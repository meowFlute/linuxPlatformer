#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>

class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	SDL_Event eventSDL;
private:
};

#endif