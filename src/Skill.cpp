// #include "Skill.h"
// #include <iostream>
// #include "Element.h"

// using namespace std;

// SkillEngimon :: SkillEngimon(){
// 	this->basePower = 0;
// 	this->masteryLvl = 1;
// 	this->Skill = "NULL";
// 	this->jmlElmt = 0
// 	this->elements = new Element[this->jmlElmt];
// }
// SkillEngimon :: SkillEngimon(char Skill, int basePower, int masteryLvl, int jmlElmt){
// 	this->basePower = basePower;
// 	this->masteryLvl = masteryLvl;
// 	this->Skill = Skill;
// 	this->jmlElmt = jmlElmt;
// 	this->elements = new Element[this->jmlElmt];
// }
// SkillEngimon :: SkillEngimon(const SkillEngimon& s){
// 	this->basePower = s->basePower;
// 	this->masteryLvl = s->masteryLvl;
// 	this->Skill = s->Skill;
// 	this->elements = new Element [s->jmlElmt];
// 	for (i = 0; i < s->jmlElmt; i++){
// 		this->elements[i] = s->elements[i];
// 	}
// }
// SkillEngimon :: ~SkillEngimon(){
// 	delete this;
// }

// Element SkillEngimon :: GetElements( int x){
// 	if (x < this->jmlElmt){
// 		return this->elements[x];
// 	}
// }

// void SkillEngimon :: SetElements(Element E){
// 	this->elements[this->jmlElmt] = E;
// 	this->jmlElmt++
// }

// bool SkillEngimon :: isThereSameElmt(SkillEngimon& S, Engimon E){
// 	bool found = false;
// 	for (i = 0; i < S->jmlElmt; i++){
// 		if (GetElements(i) == getElement(E)){
// 			found = true;
// 		}
// 	}
// 	return found;
// }

// //void learn(SkillEngimon S, Engimon E){
// //	if (isFull()){
// //		throw (LearnExp(SLOT_SKILL_FULL));
// //	}else {
// //		if (isThereSameElmt(S, E)){
// //			if (isThereSameSkill(S, E)){
// //				throw (LearnExp(THERE_IS_SAME_SKILL));
// //			}else{
// //				addSkillToEngimon(S, E);
// //			}
// //		}else{
// //			throw (LearnExp(NOT_SAME_ELMT));
// //		}
// //	}
// //}
// void replaceSkillEngimon(SkillEngimon S, Engimon E){
// 	char comfirm;
// 	int x;
// 	cout << "Replace? (Y/N) : ";
// 	cin >> confirm;
// 	if (confirm == "Y"){
// 		showEngimonSkills(E);
// 		cout << "Skill yang ingin direposisi (1/2/3/4):";
// 		cin >> x;
// 		E->Skill[x-1] = S;
// 		cout << "Reposisi Skill selesai ...";
// 	}
// }

// //void learnSkillItem(SkillEngimon S, Inventory I){
// //	if (isFullInventory(I)){
// //		throw (LearnExp(INVENTORY_FULL));
// //	}else{
// 		//cari nama skill yang sesuai dalam inventory dan jumlahnya tambahkan satu
// 		//for (i = 0; i < I->capacity; i++){
// 			//if 
// 		}
// 	}
// }
