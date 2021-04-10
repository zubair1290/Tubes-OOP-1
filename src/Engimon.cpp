#include "Engimon.h"

Engimon::Engimon() {}
Engimon::~Engimon() {}

bool Engimon::getActive() const { return active; }

ElementType Engimon::getElementType() const {
    return elementtype;
}
int Engimon::sumTotalSkillPower(){
    return skill.getbasePower()*skill.getmasteryLvl();
}

int Engimon::getLevel() const {
    return level;
}

Skill Engimon::getSkill()  {
    return skill;
}

std::string Engimon::getSpecies() const {
    return species;
}