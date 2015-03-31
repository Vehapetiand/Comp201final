#include "controller.h"
#include <map>

using namespace std;

Controller::Controller() {
	int screen_height = 768
	int screen_width = 1080
    model = new Model();
    view = new View("Game", screen_width, screen_height);
}

Controller::~Controller() {
    delete model;
    delete view;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
    SDL_Event e;
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, Direction> direction;
    direction[SDLK_UP] = UP;
    direction[SDLK_DOWN] = DOWN;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;

    while(!model->gameOver()) {
        currentTime = SDL_GetTicks();
        // Do stuff here to animate as necessary
        view->show(model);
        if (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                return;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                case SDLK_DOWN:
                case SDLK_UP:
                case SDLK_LEFT:
                case SDLK_RIGHT:
//                    model->go(direction[e.key.keysym.sym]);
                break;
                default:
                break;
                }
            case SDL_MOUSEBUTTONDOWN:
                break;
            }
        }
    }
    // TODO: show something nice?
    view->show(model);
    SDL_Delay(3000);
}


void person::person()
{
	posX = 0;
	posY = 0;
	velX = 0;
	velY = 0;
};
void person::move()
{
    //Move the dot left or right
    posX += velX;

    //If the dot went too far to the left or right
    if( ( posX < 0 ) || ( posX + person_height > screen_width ) )
    {
        //Move back
        posX -= velX;
    }

    //Move the dot up or down
    posY += velY;

    //If the dot went too far up or down
    if( ( posY < 0 ) || ( posY + person_height > screen_height ) )
    {
        //Move back
        posY -= velY;
    }
}