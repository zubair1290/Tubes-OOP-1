#include "Coordinate.h"
#include "Engimon.h"
#include "Player.h"

#ifndef __ENGIMONPLAYER_H__
#define __ENGIMONPLAYER_H__

class EngimonPlayer: public Engimon {
private:
    static std::vector<Coordinate> coordinates;
    
public:
    EngimonPlayer();
    ~EngimonPlayer();

    static std::vector<Coordinate> getCoordinates();

    static bool isCollisionWithEngimonPlayer(Coordinate _coordinate);
};

#endif