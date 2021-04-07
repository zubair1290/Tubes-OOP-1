#ifndef __ENGIMON_H__
#define __ENGIMON_H__

#include "Organism.h"
#include <bits/stdc++.h>
#include "ElementType.h"
#include "Skill.h"
#include <string>
class Engimon: public Organism {
protected:

    std::string species;
    bool active;
    ElementType elementtype;
    int level;
    Skill skill;
public:
    Engimon();
    ~Engimon();
    
    bool getActive() const;
    ElementType getElementType() const;
    int getLevel() const;
    Skill getSkill();
    std::string getSpecies() const;
    int sumTotalSkillPower() ;
};

#endif