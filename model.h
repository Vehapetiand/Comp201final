#ifndef _MODEL_H
#define _MODEL_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

enum Direction { UP, LEFT, RIGHT, DEAD, DOWN};

typedef SDL_Rect Coordinate;
 


// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    bool gameOver();
    // Which way is the player moving?
    Direction direction;
    // What's the width?
    int width;
    // What's the height?
    int height;
	//Coordinate for character
	Coordinate character;
	Coordinate floor;
	Coordinate cloud;
	//Moves the Character left or right
	void Walk(Direction d);
	//Makes Character Jump
	void Jump(Direction d);
	void Fall();
	
	
};


#endif