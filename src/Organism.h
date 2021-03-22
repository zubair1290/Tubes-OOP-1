#ifndef __ORGANISM_H__
#define __ORGANISM_H__

#include "Coordinate.h"

class Organism {
protected:
    Coordinate coordinate;


public:
    Organism();
    ~Organism();
    
    int getX();
    int getY();

    Coordinate getCoordinate();

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};

#endif