#include "Engimon.h"

Engimon::Engimon() {}
Engimon::~Engimon() {}

bool Engimon::getActive() { return active; }

Element Engimon::getElement() {
    return element;
}