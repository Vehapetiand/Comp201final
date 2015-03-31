#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return false;
}

class person
{
	public;
		static const int person_height = 45;
		static const int person_width = 45;
	
		static const int person_vel = 10;
	
		Dot();
	
		void handleEvent(SDL_Event& e );
		void move();
		void render();
	
	private;
		int posX, posY;
		int velX, velY;
};




