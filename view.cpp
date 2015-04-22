#include "view.h"

using namespace std;
int walkingframes =0;
int frame =0;

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
	renderer = SDL_CreateRenderer(window, -1,0);
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
	EndGame = load("assets/Gameover.png");
	cloud1 = load("assets/cloud1.png");
	cloud2 = load("assets/cloud2.png");
	Thesun = load("assets/sun.png");
	groundmedium = load("assets/groundmedium.png");
	groundhigh = load("assets/groundhigh.png");
	Cowboy = load("assets/Character/Cowboy2.png");
	Title = load("assets/name.png");



    music = Mix_LoadMUS("assets/Music.mp3");
    if (music != NULL) {
       Mix_PlayMusic( music, -1 );
    }
    
   
}
//technically 
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
/*void View::animate()
{
	
	
	SDL_Rect dest;
	SDL_Rect Walking[walkingframes];
	
	dest.x = 0;
    dest.y = 255;
	dest.w = 45;
	dest.h = 45;
	if (frames > 3)
		frames = 0;
	
	Walking[0].y = 90;
	Walking[0].x = 225;
	Walking[0].h = 45;
	Walking[0].w = 45;
	
	Walking[1].y = 90;
	Walking[1].x = 270;
	Walking[1].h = 45;
	Walking[1].w = 45;
	
	Walking[2].y = 90;
	Walking[2].x = 315;
	Walking[2].h = 45;
	Walking[2].w = 45;
	
	Walking[3].y = 90;
	Walking[3].x = 365;
	Walking[3].h = 45;
	Walking[3].w = 45;

	SDL_SetColorKey(Cowboy, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(Cowboy, &Walking[frame] ,screen, &dest);
	frames++;
	SDL_RenderClear(renderer);
    SDL_UpdateWindowSurfaceRects(window, &Walking[frame], frame);
	
 		
}*/

void View::show(Model * model) {
	//All of these are just creating rectangle with specific x and y's
	//Only use if you want a portion of the image;
	SDL_Rect main;
	SDL_Rect gameover;
	SDL_Rect dest; 
	SDL_Rect floor;
	SDL_Rect sky;
	SDL_Rect cloud;
	SDL_Rect smallcloud;
	SDL_Rect sun;
	SDL_Rect raised;
	SDL_Rect Walking[walkingframes];
	
	dest.x = 0;
    dest.y = 255;
	dest.w = 45;
	dest.h = 45;
	
	gameover.x = 430;
	gameover.y = 150;
	
	main.x =25;
	main.y =25;
	
	Walking[0].y = 90;
	Walking[0].x = 225;
	Walking[0].h = 45;
	Walking[0].w = 45;
	
	Walking[1].y = 90;
	Walking[1].x = 270;
	Walking[1].h = 45;
	Walking[1].w = 45;
	
	Walking[2].y = 90;
	Walking[2].x = 315;
	Walking[2].h = 45;
	Walking[2].w = 45;
	
	Walking[3].y = 90;
	Walking[3].x = 365;
	Walking[3].h = 45;
	Walking[3].w = 45;


	sun.x =981;
	sun.y =-43;
	
	dest.x = model->character.x *3;
    dest.y = model->character.y;
	dest.w = 45;
	dest.h = 45;
	
	if (model->character.x > 50)
		frame = 1;
	
	cloud.x = model->othercloud.x;
	cloud.y = 120;
	cloud.h = 82;
	cloud.w = 141;
	
	smallcloud.x = model->clouds.x;
	smallcloud.y = 55;
	smallcloud.h = 82;
	smallcloud.w = 141;
	
	raised.x = 144;
	raised.y = 270;
	raised.h = 75;
	raised.w = 110;
	
	
	//Clipped the sky background so its more of the middle of the picture
	sky.x = 0;
	sky.y = 0;
	sky.w = 1100;
	sky.h = 768;
	/* ^^ this is the clipping of the picture when used in 
	SDL_BlitSurface(image,clipping part,screen image is blit to,location on screen); 
	*/
	// x and y of foreground
	floor.x = 0;
    floor.y = 300;
	floor.h = 75;
	floor.w = 3600;
	//Foreground is 3600 by 75 
	// Initial Location of Main character
	if (model->character.x > 500)
		model->gameOver();
    
	if (!(model->gameOver())){
	SDL_BlitSurface(Background,NULL,screen,NULL); // First blit background
	SDL_BlitSurface(Title,NULL,screen,&main);
	SDL_BlitSurface(groundmedium,NULL,screen,&raised);
	SDL_BlitSurface(Foreground,NULL,screen,&floor); 
	
	SDL_SetColorKey(Thesun, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(Thesun, NULL,screen,&sun);
	

	SDL_SetColorKey(cloud1, SDL_TRUE,SDL_MapRGB(screen->format,0xff,0xff,0xff));
	SDL_BlitSurface(cloud1, NULL,screen,&smallcloud);
	SDL_SetColorKey(cloud2, SDL_TRUE,SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(cloud2, NULL,screen,&cloud);
	
	// Then foreground **They need to be in this order
	SDL_SetColorKey(Cowboy, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(Cowboy, &Walking[0] ,screen, &dest);

 	// ^^ this is the character
	 
    SDL_UpdateWindowSurface(window);
	
	}
	else 
	{
	SDL_BlitSurface(Background,&sky,screen,NULL); // First blit background
	SDL_BlitSurface(groundmedium,NULL,screen,&raised);
	SDL_BlitSurface(Foreground,NULL,screen,&floor); 
	
	
	SDL_SetColorKey(Thesun, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(Thesun, NULL,screen,&sun);
	
	
	SDL_SetColorKey(cloud1, SDL_TRUE,SDL_MapRGB(screen->format,0xff,0xff,0xff));
	SDL_BlitSurface(cloud1, NULL,screen,&smallcloud);
	SDL_SetColorKey(cloud2, SDL_TRUE,SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(cloud2, NULL,screen,&cloud);
	
	SDL_BlitSurface(EndGame, NULL, screen,&gameover);
	
    SDL_UpdateWindowSurface(window);
	// Then foreground **They need to be in this order

	}
	
	
		
}


 