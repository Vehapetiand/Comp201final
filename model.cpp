#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
	
	cloud.x = -100;
	
	character.x = 0;
	character.y = 255;
	character.w = 16;
	character.h = 45;
	
	floor.x = 0;
    floor.y = 300;
	floor.h = 75;
	floor.w = 3600;
	
	

}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}
void Model::Jump(Direction d){
	
	direction = d;
	
	switch(direction){
		
		case DOWN:
		character.y++;
		break;
		
	case UP:
	character.y = 100;
	break;
	}
	
	if (SDL_HasIntersection(&character, &floor)) {
		character.y = 255;
	}
	//I was trying to do collision between raised platform and character.
	/*if (SDL_HasIntersection(&character, &raised)) {
		if(character.x < raised.x)
		{
			character.x = 143;
		}
		if (character.x > raised.x)
		{
			character.x = 255;
		}
		if (character.y > raised.y)
		{
			character.y = 225;
		}
	}*/

	
	
}
void Model::Fall(){
	
	
}
	
void Model::Walk(Direction d){
	direction = d;
	
	switch(direction) {
    case LEFT: character.x--; break;
    case RIGHT: character.x++; break;
    }
}


bool Model::gameOver() {
    return false;
}



