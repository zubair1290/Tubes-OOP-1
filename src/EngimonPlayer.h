#include "Coordinate.h"
#include "Engimon.h"
#include "Player.h"

#ifndef __ENGIMONPLAYER_H__
#define __ENGIMONPLAYER_H__

class EngimonPlayer: public Engimon {
private:
    static std::vector<Coordinate> coordinates;
    static std::vector <EngimonPlayer*> engimons;
    friend class Player;
    
public:
    EngimonPlayer();
    ~EngimonPlayer();

    static std::vector<Coordinate> getCoordinates();

    static bool isCollisionWithEngimonPlayer(Coordinate _coordinate);

    static EngimonPlayer *getEngimonActive();

    // EngimonPlayer& operator= (const EngimonPlayer &engimon_player);
};

#endif