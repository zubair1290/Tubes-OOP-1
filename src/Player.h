#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Organism.h"
#include "Coordinate.h"
#include <iostream>

class Player: public Organism {
private:
    static Coordinate coordinates;
    
public:
    Player();
    ~Player();

    static Coordinate getCoordinates();

    static bool isCollision(Coordinate &_coordinate);
};

#endif