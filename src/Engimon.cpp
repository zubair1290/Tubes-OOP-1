#include "Engimon.h"

Engimon::Engimon() {}
Engimon::~Engimon() {}

bool Engimon::getActive() const { return active; }

Element Engimon::getElement() const {
    return element;
}

int Engimon::getLevel() const {
    return level;
}