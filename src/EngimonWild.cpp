#include "EngimonWild.h"
#include <iostream>
#include "Element.h"
#include "Player.h"
#include "EngimonPlayer.h"
#include <bits/stdc++.h>

std::vector<Coordinate> EngimonWild::coordinates;

EngimonWild::EngimonWild() {
    element = ((Element) (std::rand() % 8));
    level = std::rand() % 30;
    do {
        switch (element) {
            case Water:
            case Ice:
            case Water_Ice:
                coordinate = Coordinate::make((std::rand() % 21)*2 + 36, (std::rand() % 15)+1);
                break;
            case Fire:
            case Fire_Electric:
            case Ground:
            case Electric:
                int x, y;
                y = (std::rand() % 28)+1;
                if (y <= 15)
                    x = ((std::rand() % 17)+1)*2;
                else
                    x = ((std::rand() % 38)+1)*2;
                coordinate = Coordinate::make(x, y);
                break;
            case Water_Ground:
                coordinate = Coordinate::make(((std::rand() % 38)+1)*2, (std::rand() % 28)+1);
                break;
        }
        // std::cout << "coordinate: "<< coordinate.x << " " << coordinate.y << '\n';
        
    } while (EngimonWild::isCollision(coordinate));

    coordinates.push_back(coordinate);
}

EngimonWild::~EngimonWild() {}

bool EngimonWild::isCollision(Coordinate _coordinate) {
    return (_coordinate == Player::getCoordinates()) ||
    (EngimonPlayer::isCollisionWithEngimonPlayer(_coordinate)) ||
    (isCollisionWithEngimonWild(_coordinate)) ||
    (_coordinate.getX() <= 0 || _coordinate.getY() <= 0 || _coordinate.getX() >= 78 || _coordinate.getY() >= 29);
}

bool EngimonWild::isInArea(Coordinate _coordinate) const {
    switch (element) {
        case Water:
        case Ice:
        case Water_Ice:
            return (_coordinate.getX() >= 36 && _coordinate.getY() <= 15);
        case Fire:
        case Fire_Electric:
        case Ground:
        case Electric:
            return (_coordinate.getY() <= 15 && _coordinate.getX() <= 34) || (_coordinate.getY() >= 16 && _coordinate.getX() >= 36);
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
