#ifndef __ENGIMONWILD_H__
#define __ENGIMONWILD_H__

#include "Engimon.h"
#include "Coordinate.h"
// #include <bits/stdc++.h>
#include <vector>

class EngimonWild: public Engimon {
private:
    static std::vector<Coordinate> coordinates;
public:
    EngimonWild();
    ~EngimonWild();

    bool isInArea(Coordinate _coordinate) const;
    
    static bool isCollision(Coordinate _coordinate);

    static bool isCollisionWithEngimonWild(Coordinate _coordinate);
    
    bool duel(EngimonWild engLiar);
};

#endif