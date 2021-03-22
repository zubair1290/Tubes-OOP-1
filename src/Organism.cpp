#include "Organism.h"

Organism::Organism() {

}

Organism::~Organism() {
    
}

Coordinate Organism::getCoordinate() { return coordinate; }

int Organism::getX() { return coordinate.x; }
int Organism::getY() { return coordinate.y; }

void Organism::MoveUp() { coordinate.y--; }
void Organism::MoveDown() { coordinate.y++; }
void Organism::MoveLeft() { coordinate.x-=2; }
void Organism::MoveRight() { coordinate.x+=2; }