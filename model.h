#ifndef _MODEL_H
#define _MODEL_H

enum Direction { UP, LEFT, RIGHT, DEAD };

typedef struct {
    int x;
    int y;
} Coordinate;


// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    bool gameOver();
    // Which way is the snake moving?
    Direction direction;
    // What's the width?
    int width;
    // What's the height?
    int height;
	//Coordinate for character
	Coordinate character;
	//Moves the Character left or right
	void Walk(Direction d);
	//Makes Character Jump
	void Jump(Direction d);
	
	
};


#endif