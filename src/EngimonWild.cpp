#include "EngimonWild.h"
#include <iostream>
#include "Element.h"

EngimonWild::EngimonWild() {
    element = (Element) (std::rand() % 6);
    x = ((std::rand() % 11)+1)*2;
    y = ((std::rand() % 30)+1)*2;
}

EngimonWild::~EngimonWild() {}
