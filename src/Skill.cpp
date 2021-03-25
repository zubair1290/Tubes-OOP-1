#include "Skill.h"

Skill::Skill() {}

Skill::~Skill() {}


#include <iostream>

using namespace std;

SkillEngimon :: SkillEngimon(){
	this->basePower = 0;
	this->masteryLvl = 1;
	// this->Skill = "NULL";
	this->jmlElmt = 0;
	this->elements = new char[this->jmlElmt];
}
SkillEngimon :: SkillEngimon(char Skill, int basePower, int masteryLvl, int jmlElmt){
	this->basePower = basePower;
	this->masteryLvl = masteryLvl;
	this->Skill = Skill;
	this->jmlElmt = jmlElmt;
	this->elements = new char[this->jmlElmt];
}
SkillEngimon :: SkillEngimon(const SkillEngimon& s){
	this->basePower = s.basePower;
	this->masteryLvl = s.masteryLvl;
	this->Skill = s.Skill;
	this->elements = new char [s.jmlElmt];
	for (int i = 0; i < s.jmlElmt; i++){
		this->elements[i] = s.elements[i];
	}
}
SkillEngimon :: ~SkillEngimon(){
	delete this;
}

// char SkillEngimon :: GetElements(){
// 	return this->elements;
// }

void SkillEngimon :: SetElements(char Elmt){
	this->elements[this->jmlElmt] = Elmt;
	this->jmlElmt++;
}

// void learn(SkillEngimon S, Engimon E){
// 	if (isFull()){
// 		throw (LearnExp(SLOT_SKILL_FULL));
// 	}else {
// 		if (isThereSameElmt(S, E)){
// 			addSkillToEngimon();
// 		}else{
// 			throw (LearnExp(NOT_SAME_ELMT));
// 		}
// 	}
// }

// void learnSkillItem(SkillEngimon S, Inventory I){
// 	if (isFullInventory(I)){
// 		throw (LearnExp(INVENTORY_FULL));
// 	}else{
// 		for (i = 0; i < I->capacity; i++){
// 			if 
// 		}
// 	}
// }
