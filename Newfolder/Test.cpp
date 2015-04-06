#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#define SDL_MAIN_HANDLED

const int SCREEN_W = 640;
const int SCREEN_H = 480;

int main (int argc, char* argv[] )
{
	SDL_Window* window = NULL;
	
	SDL_Surface* screenSurface = NULL;
	
	if (SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		printf ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	 
	else
	{
		window = SDL_CreateWindow ( "SDL Tutorial bitchess", 0, 0, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN );	
		if ( window == NULL )
		{
			printf  ( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			screenSurface = SDL_GetWindowSurface (window);
			
			SDL_FillRect (screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF )); 
			
			SDL_UpdateWindowSurface (window);
			
			SDL_Delay (2000);
		}
		
	}
	
	
	
	SDL_DestroyWindow (window);
	
	SDL_Quit();
}