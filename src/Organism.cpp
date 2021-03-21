#include "Organism.h"

Organism::Organism() {

}

Organism::~Organism() {
    
}

int Organism::getX() { return x; }
int Organism::getY() { return y; }

void Organism::MoveUp() { y--; }
void Organism::MoveDown() { y++; }
void Organism::MoveLeft() { x-=2; }
void Organism::MoveRight() { x+=2; }