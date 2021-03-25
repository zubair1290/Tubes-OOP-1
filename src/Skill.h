#ifndef __SKILL_H__
#define __SKILL_H__

#include "Engimon.h"

class Skill {
private:
public:
    Skill();
    ~Skill();
};

class SkillEngimon {
	private :
		char Skill;
		int basePower;
		int masteryLvl;
		char *elements;
		int jmlElmt;
	public :
		SkillEngimon();
		SkillEngimon(char Skill, int basePower, int masteryLvl, int jmlElmt);
		SkillEngimon(const SkillEngimon&);
		~SkillEngimon();
		
		char GetElements();
		
		void SetElements(char Elmt);
		
		void learn(SkillEngimon S, Engimon E);
};

#endif
