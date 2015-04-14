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

void Model::move()
{
	
	switch(direction)
{
    case LEFT: dest.x--; break;
    case RIGHT: dest.x++; break;
}
}



bool Model::gameOver() {
    return false;
}



