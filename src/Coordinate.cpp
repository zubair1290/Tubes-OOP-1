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

Coordinate Coordinate::operator+ (const Coordinate &coordinate) const {
    Coordinate co(this->x, this->y);
    co.x += coordinate.x;
    co.y += coordinate.y;
    return co;
}

Coordinate Coordinate::operator- (const Coordinate &coordinate) const {
    Coordinate co(this->x, this->y);
    co.x -= coordinate.x;
    co.y -= coordinate.y;
    return co;
}

void Coordinate::operator+= (const Coordinate &coordinate) {
    this->x += coordinate.x;
    this->y += coordinate.y;
}

void Coordinate::operator-= (const Coordinate &coordinate) {
    this->x -= coordinate.x;
    this->y -= coordinate.y;
}

Coordinate& Coordinate::operator= (const Coordinate &coordinate) {
    this->x = coordinate.x;
    this->y = coordinate.y;
    return *this;
}

Coordinate Coordinate::make(int x, int y) {
    Coordinate co(x, y);
    return co;
}

int Coordinate::getX() const {
    return x;
}
int Coordinate::getY() const {
    return y;
}
