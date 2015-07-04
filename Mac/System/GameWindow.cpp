#include "GameWindow.h"

GameWindow::GameWindow(void)
{
	viewingScreen = NULL;
	imageBuffer = NULL;
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
			viewingScreen = SDL_GetWindowSurface( window );
		}
	}

	return success;
}

bool GameWindow::loadMedia()
{
	bool success = true;

	//imageBuffer = SDL_LoadBMP( "resources/hello_world.bmp" );
	//if( imageBuffer == NULL )
	//{
	//	printf( "Unable to load image %s! SDL Error: %s\n", "resources/hello_world.bmp", SDL_GetError() );
	//	success = false;
	//}

	return success;
}

void GameWindow::close()
{
	//SDL_FreeSurface( imageBuffer );
	imageBuffer = NULL;

	SDL_DestroyWindow( window );
	window = NULL;

	SDL_Quit();
}

SDL_Surface* GameWindow::get_viewingScreen()
{
	return viewingScreen;
}


SDL_Surface* GameWindow::get_imageBuffer()
{
	return imageBuffer;
}

void GameWindow::set_imageBuffer(SDL_Surface* image)
{	
	imageBuffer = image;
}

SDL_Window* GameWindow::get_window()
{
	return window;
}
