#include "view.h"

using namespace std;

// Initialize SDL
View::View(string title, int width, int height) {
    fail = false;
    SDL_SetMainReady();
    

	
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        fail = true;
        return;
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fail = true;
        return;
    }
    // Get the screen
    screen = SDL_GetWindowSurface(window);
    //Initialize JPEG and PNG loading
    if( !( IMG_Init( IMG_INIT_JPG|IMG_INIT_PNG ) & (IMG_INIT_JPG|IMG_INIT_PNG) ) ) {
        fail = true;
        return;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        fail = true;
        return;
    }

    // Initialize True type fonts
    if( TTF_Init() == -1 ) {
        return;
    }
    // Load assets
	Main_idle = load("assets/Main_idle.png");
	Main_walk1 = load("assets/Main_walk1.png");
	Main_walk2 = load("assets/Main_walk2.png");
	Main_walk3 = load("assets/Main_walk3.png");
	Main_jump = load("assets/Main_jump.png");
	Background = load("assets/Background.png");
	Foreground = load ("assets/Foreground.png");
	EndGame = load("assets/Endgame.png");

	

	
	
	
    music = Mix_LoadMUS("assets/Song.mp3");
    if (music != NULL) {
       Mix_PlayMusic( music, -1 );
    }
    
   
}

View::~View() {
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit(); 
}

/**
 *  Load an image from a file to a SDL_Surface
 */
SDL_Surface* View::load(char * path) {
    // Load image
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL ) {
        return NULL;
    }
    // Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, 0 );
   
    // Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    
    return optimizedSurface;
}

void View::show(Model * model) {
	//All of these are just creating rectangle with specific x and y's
	//Only use if you want a portion of the image;
	SDL_Rect dest; 
	SDL_Rect floor;
	SDL_Rect sky;
	//Clipped the sky background so its more of the middle of the picture
	sky.x = 0;
	sky.y = 300; 
	/* ^^ this is the clipping of the picture when used in 
	SDL_BlitSurface(image,clipping part,screen image is blits to,location on screen); 
	*/
	sky.w = 3600;
	sky.h = 768;
	// x and y of foreground
	floor.x = 0;
    floor.y = 300;
	floor.h = 75;
	floor.w = 3600;
	//Foreground is 3600 by 75 
	// Initial Location of Main character
    dest.x = 5;
    dest.y = 255;
	dest.w = 16;
	dest.h = 16;
	SDL_BlitSurface(Background,&sky,screen,NULL); // First blits background
	SDL_BlitSurface(Foreground,NULL,screen,&floor); 
	// Then foreground **They need to be in this order
 	SDL_BlitSurface(Main_idle,NULL,screen,&dest); 
	SDL_SetColorKey(Main_idle, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	// ^^ this is the character

	 
    SDL_UpdateWindowSurface(window);
	
	
	
	
		
}
