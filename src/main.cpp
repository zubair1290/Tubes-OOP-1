#include <iostream>
#include <fstream>
#include "Player.h"
#include "EngimonPlayer.h"
#include "EngimonWild.h"
#include <bits/stdc++.h>


void showMap();
void updatePlayerMap();
void moveEngimonLiar();
void updateMap(int x, int y);
void updateEngimonWildMap();

Player player;
std::vector<EngimonWild*> engimon_liar;
char map[30][111];

int main() {
    std::string command;
    {   // Read File
        std::ifstream read_file("./Map/map.txt");
        std::string r_line;
        int i=0;
        while (std::getline(read_file, r_line)) {
            map[i][110] = '\0'; 
            std::copy(r_line.begin(), r_line.end(), map[i++]);
        }
        read_file.close();
    }
    updatePlayerMap();
    int count_spawn_engimon_liar = 0;

    do {
        // Spawn Engimon Wild
        if (count_spawn_engimon_liar % 15 == 0) {
            EngimonWild *engimon = new EngimonWild();
            engimon_liar.push_back(engimon);
        }

        updateEngimonWildMap();
        showMap();
        std::cout << "=> ";
        std::cin >> command;
        if (command == "w" || command == "a" || command == "s" || command == "d") {
            int x = player.getX();
            int y = player.getY();
            if (command == "w") {
                Coordinate coordinate(x, y-1);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    player.MoveUp();
                    updatePlayerMap();
                }
            } else if (command == "a") {
                Coordinate coordinate(x-2, y);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    player.MoveLeft();
                    updatePlayerMap();
                }
            } else if (command == "s") {
                Coordinate coordinate(x, y+1);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    player.MoveDown();
                    updatePlayerMap();
                }
            } else if (command == "d") {
                Coordinate coordinate(x+2, y);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    player.MoveRight();
                    updatePlayerMap();
                }
            }
        }

        moveEngimonLiar();
        count_spawn_engimon_liar++;

        std::cout << "\n\n";
    } while (command != "q");

    for (int i=0; i < engimon_liar.size(); i++) {
        delete engimon_liar[i];
    }
    return 0;
}

// showing the map
void showMap() {
    std::cout << 
    "x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x\n" <<
    "x                                                                             x\n" << 
    "x                               Engimon Factory                               x\n" <<
    "x                                                                             x\n"; 
    // std::string x = "x - - - - - - - - - - - - - - - - - o o o o o o o o o o o o o o o o o o o o o x     L/l: Fire/Electric engimon";
    // std::cout << x.length() << '\n';
    for (int i=0; i < 30; i++) {
        std::cout << map[i] << '\n';
    }
    std::cout << "Player: (" << player.getX() << ',' << player.getY() << ")\n";
}

// update map coordinate after object move
void updateMap(int x, int y) {
    if (x <= 34) {
        map[y][x] = '-';
    } else if (x >= 36) {
        if (y <= 15) {
            map[y][x] = 'o';
        } else {
            map[y][x] = '-';
        }
    }
}

// write engimonwild in map 
void updateEngimonWildMap() {
    for (int i=0; i < engimon_liar.size(); i++) {
        int x = engimon_liar[i]->getX(), y = engimon_liar[i]->getY();
        switch (engimon_liar[i]->getElement()) {
        case Water:
            map[y][x] = 'W';
            break;
        case Ice:
            map[y][x] = 'I';
            break;
        case Fire:
            map[y][x] = 'F';
            break;
        case Ground:
            map[y][x] = 'G';
            break;
        case Electric:
            map[y][x] = 'E';
            break;
        case Fire_Electric:
            map[y][x] = 'L';
            break;
        case Water_Ice:
            map[y][x] = 'S';
            break;
        case Water_Ground:
            map[y][x] = 'N';
            break;
        }
    }
}

// write player in map
void updatePlayerMap() {
    map[player.getY()][player.getX()] = 'P';
}

// move engimon liar randomly
void moveEngimonLiar() {
    for (int i=0; i < engimon_liar.size(); i++) {
        int move = std::rand() % 4;
        switch (move) {
            // move right
            case 0: {
                Coordinate coordinate(engimon_liar[i]->getX() + 2, engimon_liar[i]->getY());
                if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                    updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                    engimon_liar[i]->MoveRight();
                }
                break;
            }
            // move down
            case 1: {
                Coordinate coordinate(engimon_liar[i]->getX(), engimon_liar[i]->getY()+1);
                if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                    updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                    engimon_liar[i]->MoveDown();
                }
                break;
            }
            // move left
            case 2: {
                Coordinate coordinate(engimon_liar[i]->getX()-2, engimon_liar[i]->getY());
                if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                    updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                    engimon_liar[i]->MoveLeft();
                }
                break;
            }
            // move up
            case 3: {
                Coordinate coordinate(engimon_liar[i]->getX(), engimon_liar[i]->getY()-1);
                if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                    updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                    engimon_liar[i]->MoveUp();
                }
                break;
            }
        }
    }

}