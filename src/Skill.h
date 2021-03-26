#ifndef __SKILL_H__
#define __SKILL_H__

#include "Engimon.h"
#include "Element.h"

class Skill {
	private :
		char skill;
		int basePower;
		int masteryLvl;
		Element[] elements;
		int jmlElmt;
	public :
		Skill();
		Skill(char s, int bp, int ml, int je, Element[] e);
		// Skill(const Skill&);
		~Skill();

		bool operator==(const Skill&) const;
		
		// char GetElements();
		
		// void SetElements(char Elmt);
		
		// void learn(Skill S, Engimon E);
};


#endif
