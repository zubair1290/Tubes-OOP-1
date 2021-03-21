#include <iostream>
#include <fstream>
#include "Player.h"
#include "EngimonWild.h"
#include <bits/stdc++.h>


void showMap();
void updateMap();
void updatePlayerMap();
void updatePlayerMap(int x, int y);
bool isCollisionPlayer(int x, int y);
bool isCollisionEngimon(int x, int y);

Player player;
std::vector<EngimonWild*> engimon_liar;
char map[27][100];

int main() {
    std::string command;
    {   // Read File
        std::ifstream read_file("./Map/map.txt");
        std::string r_line;
        int i=0;
        while (std::getline(read_file, r_line)) {
            map[i][100] = '\0'; 
            std::copy(r_line.begin(), r_line.end(), map[i++]);
        }
        read_file.close();
    }
    updatePlayerMap();
    updateMap();
    int count_spawn_engimon_liar = 0;

    do {
        // Spawn Engimon Wild
        if (count_spawn_engimon_liar % 15 == 0) {
            EngimonWild *engimon = new EngimonWild();
            engimon_liar.push_back(engimon);
        }

        updateMap();
        showMap();
        std::cout << "=> ";
        std::cin >> command;
        if (command == "w") {
            int x = player.getX();
            int y = player.getY();
            if (!isCollisionPlayer(x, y-1)) {

                player.MoveUp();
                updatePlayerMap(x, y);
            }
        } else if (command == "a") {
            int x = player.getX();
            int y = player.getY();

            if (!isCollisionPlayer(x-2, y)) {
                player.MoveLeft();
                updatePlayerMap(x, y);
            }
        } else if (command == "s") {
            int x = player.getX();
            int y = player.getY();

            if (!isCollisionPlayer(x, y+1)) {
                player.MoveDown();
                updatePlayerMap(x, y);
            }
        } else if (command == "d") {
            int x = player.getX();
            int y = player.getY();

            if (!isCollisionPlayer(x+2, y)) {
                player.MoveRight();
                updatePlayerMap(x, y);
            }
        }
        count_spawn_engimon_liar++;

        
        std::cout << "\n\n";
    } while (command != "q");

    for (int i=0; i < engimon_liar.size(); i++) {
        delete engimon_liar[i];
    }
    return 0;
}

void showMap() {
    std::cout << 
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" <<
    "x                                                                 x\n" << 
    "x                         Engimon Factory                         x\n" <<
    "x                                                                 x\n"; 
    for (int i=0; i < 27; i++) {
        std::cout << map[i] << '\n';
    }
}

void updateMap() {
    for (int i=0; i < engimon_liar.size(); i++) {
        map[engimon_liar[i]->getY()][engimon_liar[i]->getX()] = 'L';
    }
}

void updatePlayerMap(int x, int y) {
    map[y][x] = '-';
    map[player.getY()][player.getX()] = 'P';
}

void updatePlayerMap() {
    map[player.getY()][player.getX()] = 'P';
}

bool isCollisionPlayer(int x, int y) {
    for (int i=0; i < engimon_liar.size(); i++) {
        if (engimon_liar[i]->getX() == x && engimon_liar[i]->getY() == y) return true;
    }
    return (x <= 0 || y <= 0 || x >= 66 || y >= 26);
}

bool isCollisionEngimon(int x, int y) {
    return (x == player.getX() || y == player.getY()) ||
        (x <= 0 || y <= 0 || x >= 67 || y >= 67);
}

void moveEngimonLiar() {
    for (int i=0; i < engimon_liar.size(); i++) {
        int x_move = ((std::rand() % 3)-1)*2;
        if (x_move == 0) {
            int y_move = (std::rand() % 3) -1;
            if (!isCollisionEngimon(engimon_liar[i]->getX(), engimon_liar[i]->getY()+y_move)) {
                switch (y_move) {
                    case -1:
                        engimon_liar[i]->MoveUp();
                        break;
                    case 1:
                        engimon_liar[i]->MoveDown();
                        break;
                }
            }
        } else {
            if (!isCollisionEngimon(engimon_liar[i]->getX()+x_move, engimon_liar[i]->getY())) {
                switch (x_move) {
                    case -2:
                        engimon_liar[i]->MoveLeft();
                        break;
                    case 2:
                        engimon_liar[i]->MoveRight();
                        break;
                }
            }
        }
    }
}