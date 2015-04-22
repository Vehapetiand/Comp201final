#include "model.h"
#include <cstdlib>
#include <ctime>


using namespace std;
int ii =0;
// Constructor initializes the object
Model::Model() {
<<<<<<< HEAD
	
	cloud.x = -100;
=======
	clouds.x = -100;
	othercloud.x = 300;
>>>>>>> 8fd5be033ea2f3d2773a29e65c94e48384145962
	
	character.x = 0;
	character.y = 255;
	character.w = 16;
	character.h = 45;
	
	floor.x = 0;
    floor.y = 300;
	floor.h = 75;
	floor.w = 3600;
	
<<<<<<< HEAD
	raised.x = 144;
	raised.y = 270;
	raised.h = 75;
	raised.w = 110; 
	
	

=======
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
		
	
>>>>>>> 8fd5be033ea2f3d2773a29e65c94e48384145962
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}
void Model::Jump(Direction d){
	
	direction = d;
	
<<<<<<< HEAD
	switch(direction){
		
		case DOWN:
		character.y += 10;
		break;
		
	case UP:
	character.y -= 30;
	break;
	}
	
	
	if (SDL_HasIntersection(&character, &floor)) {
		character.y = 255;
=======
	switch(direction) {
    case UP: character.y = character.y -75; break;
	case UPL: 
	character.y = 200; ; break;
    character.x = character.x -75;
	case UPR:
	character.x = character.x +75; 
	character.y = character.y -75;
	break;
>>>>>>> 8fd5be033ea2f3d2773a29e65c94e48384145962
	}
	
	
	
<<<<<<< HEAD
	
}
void Model::Fall(){
	

=======
>>>>>>> 8fd5be033ea2f3d2773a29e65c94e48384145962
}
	
void Model::Walk(Direction d){
	direction = d;
	
	switch(direction) {
    case LEFT: character.x = 0; ; break;
    case RIGHT: character.x = character.x +5; break;
    }
	if (character.x > 332)
	{
		character.x = 332;
	}
	if (character.x < 0)
	{
		character.x = 0;
	}
	
	//I was trying to do collision between raised platform and character.
	if (SDL_HasIntersection(&character, &raised)) {
		character.y -= 100;
		/*if(character.x < raised.x)
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
		}*/
	}
}




bool Model::gameOver() {
<<<<<<< HEAD
	

    return false;
=======

	if ( character.x > 336)
	{return true;}

		
>>>>>>> 8fd5be033ea2f3d2773a29e65c94e48384145962
}



