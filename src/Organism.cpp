#include "Organism.h"

Organism::Organism() {

}

Organism::~Organism() {
    
}

Coordinate Organism::getCoordinate() { return coordinate; }

int Organism::getX() { return coordinate.getX(); }
int Organism::getY() { return coordinate.getY(); }

void Organism::MoveUp() { coordinate -= Coordinate::make(0, 1); }
void Organism::MoveDown() { coordinate += Coordinate::make(0, 1); }
void Organism::MoveLeft() { coordinate -= Coordinate::make(2, 0); }
void Organism::MoveRight() { coordinate += Coordinate::make(2,0); }