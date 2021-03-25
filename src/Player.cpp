#include "Player.h"
#include "EngimonWild.h"

Coordinate Player::coordinates;

Player::Player(int x, int y) {
    coordinate.x = x;
    coordinate.y = y;

    coordinates = coordinate;
}

Player::~Player() {

}

Coordinate Player::getCoordinates() { return coordinates; }

bool Player::isCollision(Coordinate& _coordinate) {
    return (EngimonWild::isCollisionWithEngimonWild(_coordinate)) ||
        (_coordinate.x <= 0 || _coordinate.y <= 0 || _coordinate.x >= 78 || _coordinate.y >= 29);
}

void Player::MoveUp() {
    Organism::MoveUp();
    
}
void Player::MoveDown() {
    Organism::MoveDown();

}
void Player::MoveLeft() {
    Organism::MoveLeft();
}
void Player::MoveRight() {
    Organism::MoveRight();
}