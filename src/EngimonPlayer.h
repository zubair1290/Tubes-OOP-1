#include "Coordinate.h"
#include "Engimon.h"

class EngimonPlayer: public Engimon {
private:
    static std::vector<Coordinate> coordinates;

public:
    EngimonPlayer();
    ~EngimonPlayer();

    static std::vector<Coordinate> getCoordinates();

    static bool isCollisionWithEngimonPlayer(Coordinate _coordinate);
};

