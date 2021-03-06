
#ifndef __ENGIMONPLAYER_H__
#define __ENGIMONPLAYER_H__

#include "Coordinate.h"
#include "Engimon.h"
#include "Player.h"
#include <vector>

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

    void setLevel(int lvl);
    // EngimonPlayer& operator= (const EngimonPlayer &engimon_player);
};

#endif