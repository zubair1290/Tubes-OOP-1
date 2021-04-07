#ifndef __SKILL_H__
#define __SKILL_H__

#include "Engimon.h"
#include "ElementType.h"
#include <string>

class Skill {
	private :
		std::string skill;
		int basePower;
		int masteryLvl;
		ElementType elements;
		int jmlElmt;
	public :
		Skill();
		Skill(std::string s, int bp, int ml, int je, ElementType e);
		// Skill(const Skill&);
		~Skill();
		int getbasePower() const;
		int getmasteryLvl() const;
		std::string getSkillName() const;
		ElementType getSkillElement() const;
		bool operator==(const Skill&) const;
		//Skill operator&();
		// char GetElements();
		
		// void SetElements(char Elmt);
		
		// void learn(Skill S, Engimon E);
};


#endif
