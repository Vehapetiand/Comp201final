#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;
int ii =0;
// Constructor initializes the object
Model::Model() {
	clouds.x = -100;
	othercloud.x = 300;
	
	character.x = 0;
	character.y = 255;
	character.w = 16;
	character.h = 45;
	
	floor.x = 0;
    floor.y = 300;
	floor.h = 75;
	floor.w = 3600;
	
	bool over =0;

}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}
bool Model::Collision(){
	
	return (SDL_HasIntersection(&character, &floor));
}
void Model::Fall(){

	character.y++;
	
		
	
}

void Model::Clouds()
{
	
	if (clouds.x <= 1200){
		clouds.x++;
		clouds.x++;
	
	}
	if (othercloud.x <= 1200){
		othercloud.x++;
	}
	
	if (othercloud.x > 1200){
		othercloud.x = -200;
	}
	if (clouds.x > 1200){
		clouds.x = -200;
	}
		
	
}

void Model::Jump(Direction d){
	
	direction = d;
	
	switch(direction) {
    case UP: character.y = character.y -75; break;
	case UPL: 
	character.y = 200; ; break;
    character.x = character.x -75;
	case UPR:
	character.x = character.x +75; 
	character.y = character.y -75;
	break;
	}
	
	
	
}
void Model::Walk(Direction d){
	direction = d;
	
	switch(direction) {
    case LEFT: character.x = 0; ; break;
    case RIGHT: character.x = character.x +5; break;
    }
	
}
bool Model::gameOver() {

	if ( character.x > 336)
	{return true;}

		
}



