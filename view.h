#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "model.h"
#include <map>
#include <string>

#ifndef _VIEW_H
#define _VIEW_H

// Show (output) the state of the model
class View {
public:
    View(std::string title, int width, int height);
    ~View();
    // Print out the visible stuff in the grid
    void show(Model * model);
	void animate();
private:
    SDL_Window* window;
	SDL_Renderer* renderer;
    SDL_Surface* screen;
    bool fail;
    SDL_Surface* load(char * path);
	Mix_Music * music;
	SDL_Surface* image;
	SDL_Surface* Main_idle;
	SDL_Surface* Main_walk1;
	SDL_Surface* Main_walk2;
	SDL_Surface* Main_walk3;
	SDL_Surface* Main_jump;
	SDL_Surface* Background;
	SDL_Surface* Foreground;
	SDL_Surface* EndGame;
	SDL_Surface* cloud1;
	SDL_Surface* cloud2;
	SDL_Surface* Thesun;
	SDL_Surface* groundmedium;
	SDL_Surface* Cowboy;
	SDL_Surface* Title;
	
	//    SDL_Surface* text;
//    Mix_Music * music;
//    Mix_Chunk * food;
    TTF_Font * font;
};

class Animate {
    private:
        int    CurrentFrame;
        int     FrameInc;
    private:
        int     FrameRate; //Milliseconds
        long    OldTime;
    public:
        int    MaxFrames; 
        bool    Oscillate;
    public:
        Animate();
        void OnAnimate();
    public:
        void SetFrameRate(int Rate);
        void SetCurrentFrame(int Frame);
        int GetCurrentFrame();
};
#endif