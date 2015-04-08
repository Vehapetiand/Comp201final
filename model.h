#ifndef _MODEL_H
#define _MODEL_H

enum Direction { UP, LEFT, RIGHT, DEAD };



// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Which way should the snake face?
    void go(Direction d);
    // Is the game over?
    bool gameOver();
    // Which way is the snake moving?
    Direction direction;
    // What's the width?
    int width;
    // What's the height?
    int height;
};


#endif