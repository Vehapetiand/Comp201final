#include "controller.h"
#include <map>

using namespace std;

Controller::Controller() {
	
	model = new Model();
    view = new View("Game", 1024, 375);
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
    SDL_Event event;
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, Direction> direction;
    direction[SDLK_UP] = UP;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;
	direction[SDLK_RIGHT] = DOWN;
	

    while(!model->gameOver()) {
        currentTime = SDL_GetTicks();
        // Do stuff here to animate as necessary
        view->show(model);
			
        if (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
            case SDL_QUIT:
                return;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                
				case (SDLK_UP): model->Jump(RIGHT);break;
                case SDLK_LEFT:	model->Walk(LEFT); break;
                case SDLK_RIGHT: model->Walk(RIGHT); break;
				case SDLK_DOWN: model->Jump(DOWN); break;	
				
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
}


