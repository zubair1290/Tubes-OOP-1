#include "EngimonPlayer.h"

std::vector<Coordinate> EngimonPlayer::coordinates;

EngimonPlayer::EngimonPlayer() {
    coordinates.push_back(Player::getCoordinates() + Coordinate::make(1, 0));
    coordinate = Player::getCoordinates() + Coordinate::make(-2, 0);
    std::cout << "EP: "<< coordinate.x << ',' << coordinate.y << '\n';
    level = 0;
    element = Water;
    active = true;
}

EngimonPlayer::~EngimonPlayer() {

}

std::vector<Coordinate> EngimonPlayer::getCoordinates() {
    return coordinates;
}


bool EngimonPlayer::isCollisionWithEngimonPlayer(Coordinate _coordinate) {
    for (int i=0; i < coordinates.size(); i++) {
        if (_coordinate == coordinates[i]) return true;
    }
    return false;
}

