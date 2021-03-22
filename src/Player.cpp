#include "Player.h"
#include "EngimonWild.h"

Coordinate Player::coordinates;

Player::Player() {
    coordinate.x = 12;
    coordinate.y = 6;
    coordinates = coordinate;
}

Player::~Player() {

}

Coordinate Player::getCoordinates() { return coordinates; }

bool Player::isCollision(Coordinate& _coordinate) {
    return (EngimonWild::isCollisionWithEngimonWild(_coordinate)) ||
        (_coordinate.x <= 0 || _coordinate.y <= 0 || _coordinate.x >= 78 || _coordinate.y >= 29);
}