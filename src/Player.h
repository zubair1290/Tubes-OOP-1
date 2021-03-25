#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Organism.h"
#include "Coordinate.h"
#include "EngimonPlayer.h"
#include <iostream>

class Player: public Organism {
protected:
    static Coordinate coordinates;
    // friend class EngimonPlayer;
    
public:
    Player(int x, int y);
    ~Player();

    static Coordinate getCoordinates();

    static bool isCollision(Coordinate &_coordinate);

    void MoveUp() override;
    void MoveDown() override;
    void MoveLeft() override;
    void MoveRight() override;
};

#endif