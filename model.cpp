#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
	
	character.x = 0;
	character.y = 255;

}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}
void Model::Jump(Direction d){
	
	direction = d;
	
	switch(direction) {
		
	case UP:
	character.y--;
	break;
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



