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
        switch (element) {
            case Water:
            case Ice:
            case Water_Ice:
                coordinate.x = (std::rand() % 21)*2 + 36;
                coordinate.y = ((std::rand() % 15)+1);
                break;
            case Fire:
            case Fire_Electric:
            case Ground:
            case Electric:
                coordinate.y = (std::rand() % 28)+1;
                if (coordinate.y <= 15)
                    coordinate.x = ((std::rand() % 17)+1)*2;
                else
                    coordinate.x = ((std::rand() % 38)+1)*2;
                break;
            case Water_Ground:
                coordinate.x = ((std::rand() % 38)+1)*2;
                coordinate.y = (std::rand() % 28)+1;
                break;
        }
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

bool EngimonWild::isInArea(Coordinate _coordinate) {
    switch (element) {
        case Water:
        case Ice:
        case Water_Ice:
            return (_coordinate.x >= 36 && _coordinate.y <= 15);
        case Fire:
        case Fire_Electric:
        case Ground:
        case Electric:
            return (_coordinate.y <= 15 && _coordinate.x <= 34) || (_coordinate.y >= 16 && _coordinate.x >= 36);
        case Water_Ground:
            return true;
    }
    return true;
}

bool EngimonWild::isCollisionWithEngimonWild(Coordinate _coordinate) {
    for (int i=0; i < coordinates.size(); i++) {
        if (_coordinate == coordinates[i]) return true;
    }
    return false;
}
