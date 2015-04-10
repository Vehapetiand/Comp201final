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

<<<<<<< HEAD
 /* void person::person()
=======
/*
 void person::person()
>>>>>>> b8b1daebc0bceac135012a220db2bf252219700c
{
	posX = 0;
	posY = 0;
	velX = 0;
	velY = 0;
}
*/
<<<<<<< HEAD

=======
>>>>>>> b8b1daebc0bceac135012a220db2bf252219700c
void person::move()
{
    //Move the guy left or right
    posX += velX;

    //If the guy went too far to the left or right
    if( ( posX < 0 ) || ( posX + person_height > 1080  ) )
    {
        //Move back
        posX -= velX;
    }

    //Move the guy up or down
    posY += velY;

    //If the guy went too far up or down
    if( ( posY < 0 ) || ( posY + person_height > 768 ) )
    {
        //Move back
        posY -= velY;
    }
}



