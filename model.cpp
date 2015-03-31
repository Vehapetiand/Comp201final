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
	public:
		static const int person_height = 45;
		static const int person_width = 45;
	
		static const int person_vel = 10;
	
		person();
	
		//void handleEvent(SDL_Event& e );
		void move();
		void render();
	
	private:
		int posX, posY;
		int velX, velY;
};

void person::person()
{
	posX = 0;
	posY = 0;
	velX = 0;
	velY = 0;
}
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



