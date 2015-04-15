#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
	
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
	
	switch(direction) {
void Model::Fall(){
	while (character.y < 255)
	{	
		character.y++;
	}
		
		case DOWN:
		character.y++;
		break;
		
	case RIGHT:
	character.y--;
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

void Model::Jump(Direction d){
	
	int jumph = 5;
	direction = d;
	/*
	switch(direction) {
    case LEFT: 
	character.x--; 
	
	break;
    case RIGHT: 
	character.x++;
	//while (character.y )
	character.y--;
	break;
    }
	*/
	character.y -= jumph * 2;
	
	
	
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



