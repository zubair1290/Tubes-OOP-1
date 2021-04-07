#include "Engimon.h"

Engimon::Engimon() {}
Engimon::~Engimon() {}

bool Engimon::getActive() const { return active; }

ElementType Engimon::getElementType() const {
    return elementtype;
}
// int Engimon::sumTotalSkillPower(){
//     return skills.getbasePower()*skills.getmasteryLvl();
// }

int Engimon::getLevel() const {
    return level;
}

// Skill Engimon::getSkill()  {
//     return skills;
// }

std::string Engimon::getSpecies() const {
    return species;
}