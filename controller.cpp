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
	unsigned int lastTime2 = 0;
	int ii = 0;
    std::map<SDL_Keycode, Direction> direction;
    direction[SDLK_UP] = UP;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;
	direction[SDLK_DOWN] = DOWN;
	direction[(SDLK_UP&&SDLK_RIGHT)] = UPR;
	direction[(SDLK_UP&&SDLK_LEFT)] = UPL;
    while(!model->gameOver()) {
        currentTime = SDL_GetTicks();
		lastTime2 = lastTime;
		// Do stuff here to animate as necessary
        view->show(model);
		while (currentTime > lastTime + 75)
			{
			while (!(model->Collision())) 
				{	
					
					if (ii > 100000){
					ii=0;
					model->Fall();
					}
					else
					ii++;
					
				}
						
			model->Clouds();
			lastTime = currentTime;
			}
	
        
		
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					return;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) 
					{
					case SDLK_UP: 
					model->Jump(UP);
					break;
					
					case (UPR): 
					model->Jump(RIGHT);
					break;
					
					case (UPL): 
					model->Jump(LEFT); 
					break;
					
					case SDLK_LEFT:	
					model->Walk(LEFT); break;
					case SDLK_RIGHT: 
					model->Walk(RIGHT); break;
					
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
	SDL_Delay(5000);
	
}


