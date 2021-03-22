#include "Coordinate.h"

Coordinate::Coordinate() {
    x = 0;
    y = 0;
}

Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Coordinate::operator== (const Coordinate &coordinate) const {
    return x == coordinate.x && y == coordinate.y;
}
