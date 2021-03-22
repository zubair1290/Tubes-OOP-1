#include "EngimonWild.h"
#include <iostream>
#include "Element.h"
#include "Player.h"
#include "EngimonPlayer.h"
#include <bits/stdc++.h>

std::vector<Coordinate> EngimonWild::coordinates;

EngimonWild::EngimonWild() {
    element = ((Element) (std::rand() % 8));
    do {
        coordinate.x = ((std::rand() % 38)+1)*2;
        coordinate.y = ((std::rand() % 14)+1)*2;
        std::cout << "coordinate: "<< coordinate.x << " " << coordinate.y << '\n';
    } while (EngimonWild::isCollision(coordinate));

    coordinates.push_back(coordinate);
}

EngimonWild::~EngimonWild() {}

bool EngimonWild::isCollision(Coordinate _coordinate) {
    return (_coordinate == Player::getCoordinates()) ||
    (EngimonPlayer::isCollisionWithEngimonPlayer(_coordinate)) ||
    (isCollisionWithEngimonWild(_coordinate)) ||
    (_coordinate.x <= 0 || _coordinate.y <= 0 || _coordinate.x >= 78 || _coordinate.y >= 29);
}

bool EngimonWild::isCollisionWithEngimonWild(Coordinate _coordinate) {
    for (int i=0; i < coordinates.size(); i++) {
        if (_coordinate == coordinates[i]) return true;
    }
    return false;
}
