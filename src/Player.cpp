#include "Player.h"
#include "EngimonWild.h"

Coordinate Player::coordinates;

Player::Player(int x, int y) {
    coordinate = Coordinate::make(x, y);
    coordinates = coordinate;
}

Player::~Player() {

}

Coordinate Player::getCoordinates() { return coordinates; }

bool Player::isCollision(Coordinate& _coordinate) {
    return (EngimonWild::isCollisionWithEngimonWild(_coordinate)) ||
        (_coordinate.getX() <= 0 || _coordinate.getY() <= 0 || _coordinate.getX() >= 78 || _coordinate.getY() >= 29);
}

void Player::MoveUp() {
    Organism::MoveUp();
    coordinates = coordinate;
    for (int i=0; i < EngimonPlayer::engimons.size(); i++) {
        if (EngimonPlayer::engimons[i]->active) {
            EngimonPlayer::engimons[i]->coordinate = Player::coordinates + Coordinate::make(0, 1);
            break;
        }
    }
}
void Player::MoveDown() {
    Organism::MoveDown();
    coordinates = coordinate;
    for (int i=0; i < EngimonPlayer::engimons.size(); i++) {
        if (EngimonPlayer::engimons[i]->active) {
            EngimonPlayer::engimons[i]->coordinate = Player::coordinates + Coordinate::make(0, -1);
            break;
        }
    }

}
void Player::MoveLeft() {
    Organism::MoveLeft();
    coordinates = coordinate;
    for (int i=0; i < EngimonPlayer::engimons.size(); i++) {
        if (EngimonPlayer::engimons[i]->active) {
            EngimonPlayer::engimons[i]->coordinate = Player::coordinates + Coordinate::make(2, 0);
            break;
        }
    }
}
void Player::MoveRight() {
    Organism::MoveRight();
    coordinates = coordinate;
    for (int i=0; i < EngimonPlayer::engimons.size(); i++) {
        if (EngimonPlayer::engimons[i]->active) {
            EngimonPlayer::engimons[i]->coordinate = Player::coordinates + Coordinate::make(-2, 0);
            break;
        }
    }
}