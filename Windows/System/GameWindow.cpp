#include "GameWindow.h"

GameWindow::GameWindow(void)
{
	buffer1 = NULL;
	buffer2 = NULL;
	window = NULL;
}

GameWindow::~GameWindow(void)
{
	close();
}

bool GameWindow::init()
{
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Initialization failed. SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		window = SDL_CreateWindow( "Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window creation failed. SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			buffer1 = SDL_GetWindowSurface( window );
		}
	}

	return success;
}

bool GameWindow::loadMedia()
{
	bool success = true;

	buffer2 = SDL_LoadBMP( "hello_world.bmp" );
	if( buffer2 == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void GameWindow::close()
{
	SDL_FreeSurface( buffer2 );
	buffer2 = NULL;

	SDL_DestroyWindow( window );
	window = NULL;

	SDL_Quit();
}

SDL_Surface* GameWindow::get_buffer1()
{
	return buffer1;
}


SDL_Surface* GameWindow::get_buffer2()
{
	return buffer2;
}

SDL_Window* GameWindow::get_window()
{
	return window;
}
