#include "EngimonPlayer.h"

std::vector<Coordinate> EngimonPlayer::coordinates;

EngimonPlayer::EngimonPlayer() {
    coordinates.push_back(coordinate);
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

