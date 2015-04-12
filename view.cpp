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
<<<<<<< HEAD
	Fground = load ("assets/Foreground.png");
=======
	EndGame = load("assets/Endgame.png");
	
	
>>>>>>> 3defc26389f877049bddf87ebe178ca4da9ec06f
	
	
	
//    music = Mix_LoadMUS("assets/2Inventions_-_Johaness_Gilther_-_Don_t_leave_me.mp3");
//    if (music != NULL) {
//       Mix_PlayMusic( music, -1 );
//    }
//    
    font = TTF_OpenFont( "assets/LiberationSans-Regular.ttf", 28 );

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

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,
       255, 255, 255));
<<<<<<< HEAD
	
	SDL_FillRect(Fground, NULL, SDL_MapRGB(Fground->format,
       0, 0, 0));
	
	SDL_BlitSurface(Background,NULL,screen,NULL);
	
	SDL_BlitSurface(Fground,NULL,screen,NULL);
	
	
	
	SDL_Surface *s;

	/* Creating the surface. */
	

	/* Filling the surface with red color. */
	
	//SDL_BlitSurface(Main_idle,NULL,screen,NULL);	use sdlfillrect
	//SDL_FillRect(screen, Main_idle, SDL_MapRGB(screen->format, 255,255,255 ));	

    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
	//	 SDL_FillRect(screen, NULL, ,NULL);
=======
	   SDL_BlitSurface(Background,NULL,screen,NULL);
	   
	      SDL_Rect dest;
    dest.w = 16;
    dest.h = 16;
    
    // TODO: I went all Atari 2600 on you guys. Perhaps you'd like to upgrade
    // the view with something nice, like a cartoon snake?
    // HINT: you'd need up, down, left, and right facing assets for:
    // the snake head, a dead head, the tail, and elbows
    // HINT: you'd of course need assets for horizontal and vertical snake sections

    // Draw food
    dest.x = 0;
    dest.y = 0;
    SDL_FillRect(screen, &dest, SDL_MapRGB(screen->format,0x00, 0x00, 0x00)); 
	SDL_BlitSurface(Main_idle,NULL/*which part of image*/,screen,&dest/*where on screen*/); 
	SDL_SetColorKey(Main_idle, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	// Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
//	 SDL_FillRect(screen, NULL, ,NULL);
>>>>>>> 3defc26389f877049bddf87ebe178ca4da9ec06f
	 
    SDL_UpdateWindowSurface(window);
}
