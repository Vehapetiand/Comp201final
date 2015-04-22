#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
	clouds.x = -100;
	othercloud.x = 400;
	
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

void Model::Fall(){

	
	character.y++;
	
	
	
}

void Model::Clouds()
{
	
	clouds.x++;
	othercloud.x++;
	clouds.x++;
	
}

void Model::Jump(Direction d){
	
	direction = d;
	
	switch(direction) {
		
	case DOWN:
	character.y++;
	break;
		
	case UP:
	character.y = character.y + 100;
	break;
    }
	
	if (SDL_HasIntersection(&character, &floor)) {
		character.y = 255;
	}
	
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



