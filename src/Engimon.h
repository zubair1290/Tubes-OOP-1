#ifndef __ENGIMON_H__
#define __ENGIMON_H__

#include "Organism.h"
#include <bits/stdc++.h>
#include "Element.h"

class Engimon: public Organism {
protected:
    bool active;
    Element element;
    
public:
    Engimon();
    ~Engimon();
    
    bool getActive();
    Element getElement();

};

#endif