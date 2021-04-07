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

    virtual void MoveUp();
    virtual void MoveDown();
    virtual void MoveLeft();
    virtual void MoveRight();
};

#endif