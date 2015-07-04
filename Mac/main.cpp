//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include "System/GameWindow.h"

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT = 0,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Surface* loadSurface( std::string path );
void loadAllKeySurfaces();

int main( int argc, char* args[] )
{
	GameWindow * myWindow = new GameWindow;
	if( !myWindow->init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !myWindow->loadMedia() )
		{
			printf( "Failed to load media!\n" );
			
		}
		else
		{
			loadAllKeySurfaces();
			bool quit = false;
			
			
			while(!quit)
			{
				//handle events one by one
				while(SDL_PollEvent(&myWindow->eventHandler.eventSDL))
				{
					//quit events
					if(myWindow->eventHandler.eventSDL.type == SDL_QUIT)
					{
						quit = true;
					}
					//keypress events
					else if(myWindow->eventHandler.eventSDL.type == SDL_KEYDOWN)
					{
						switch(myWindow->eventHandler.eventSDL.key.keysym.sym)
						{
							case SDLK_UP:
							myWindow->set_imageBuffer(gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ]);
							break;

							case SDLK_DOWN:
							myWindow->set_imageBuffer(gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ]);
							break;

							case SDLK_LEFT:
							myWindow->set_imageBuffer(gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ]);
							break;

							case SDLK_RIGHT:
							myWindow->set_imageBuffer(gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ]);
							break;

							default:
							myWindow->set_imageBuffer(gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ]);
							break;
						}
					}
					//other events here
				}
				
				//apply the image buffer to the screen
				SDL_BlitSurface( myWindow->get_imageBuffer(), NULL, myWindow->get_viewingScreen(), NULL );
				SDL_UpdateWindowSurface( myWindow->get_window() );
			}
		}
	}

	//Free resources and close SDL
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}
	
	myWindow->close();

	return 0;
}

SDL_Surface* loadSurface( std::string path )
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}

	return loadedSurface;
}

void loadAllKeySurfaces()
{
	//Load default surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "resources/press.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
	{
		printf( "Failed to load default image!\n" );
	}

	//Load up surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "resources/up.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
	{
		printf( "Failed to load up image!\n" );
	}

	//Load down surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "resources/down.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
	{
		printf( "Failed to load down image!\n" );
	}

	//Load left surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "resources/left.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
	{
		printf( "Failed to load left image!\n" );
	}

	//Load right surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "resources/right.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
	{
		printf( "Failed to load right image!\n" );
	}
}