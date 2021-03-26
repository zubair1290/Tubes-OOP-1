#include "EngimonPlayer.h"

std::vector<Coordinate> EngimonPlayer::coordinates;
std::vector<EngimonPlayer*> EngimonPlayer::engimons;

EngimonPlayer::EngimonPlayer() {
    coordinates.push_back(Player::getCoordinates() + Coordinate::make(1, 0));
    coordinate = Player::getCoordinates() + Coordinate::make(-2, 0);
    engimons.push_back(this);
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

EngimonPlayer *EngimonPlayer::getEngimonActive() {
    EngimonPlayer *e;
    for (int i=0; i < engimons.size(); i++) {
        if (engimons[i]->getActive()) {
            e = engimons[i];
        }
    }
    return e;
}

// EngimonPlayer& EngimonPlayer::operator= (const EngimonPlayer &engimon_player) {
//     this->active = engimon_player.active;
//     this->element = engimon_player.element;
//     this->level = engimon_player.level;
//     this->coordinate = engimon_player.coordinate;
// }
