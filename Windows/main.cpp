//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include "System/GameWindow.h"

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
			//apply the loaded image to the surface
			SDL_BlitSurface( myWindow->get_buffer2(), NULL, myWindow->get_buffer1(), NULL );
			SDL_UpdateWindowSurface( myWindow->get_window() );

			//Wait a few seconds
			SDL_Delay( 5000 );
		}
	}

	//Free resources and close SDL
	myWindow->close();

	return 0;
}
