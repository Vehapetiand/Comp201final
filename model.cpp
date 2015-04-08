#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
	width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
    guy.x = 10;
	guy.y = 200;
    enemy.x = 50;
   enemy.y = 200;
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return false;
}




