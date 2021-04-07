#include <iostream>
#include <fstream>
#include "Player.h"
#include "EngimonPlayer.h"
#include "EngimonWild.h"
#include <bits/stdc++.h>
#include "Inventory.h"
#include "Skill.h"

void showMap();
void updatePlayerMap();
void moveEngimonLiar();
void updateMap(int x, int y);
void updateEngimonWildMap();
void viewAllEngimonWild();
void viewAllEngimonPlayer();
void updateEngimonMap(Engimon engimon);
void skill();

void battle(int x, int y);
bool duel(EngimonPlayer engPlayer, EngimonWild* engLiar);
void breed(EngimonPlayer engParentA,EngimonPlayer engParentB);
void getElementSpeciesChild(ElementType elementEngParentA,std::string speciesEngParentA,
                            ElementType elementEngParentB,std::string speciesEngParentB,
                            ElementType* elementChild,std::string *speciesChild);
void getListSkillChild(Skill listSkillEngParentA, Skill listSkillEngParentB, Skill listSkillChild,ElementType elementChild);
bool isSkillCompatibleElement(Skill skillEngimon,ElementType element);
float compareElement(ElementType a, ElementType b);


Player player(12, 6);
EngimonPlayer engimon_player;
std::vector<EngimonWild*> engimon_liar;
char map[30][111];
Inventory<EngimonPlayer> inventory_engimon;
Inventory<Skill> inventory_skill;

const char * elementNames[] = {
    "Water",
    "Ice",
    "Fire",
    "Ground",
    "Electric",
    "Fire_Electric",
    "Water_Ice",
    "Water_Ground"
};

int main() {
    std::string full_command;
    std::string command;
    {   // Read File
        std::ifstream read_file("./Map/map.txt");
        std::string r_line;
        int i=0;
        while (std::getline(read_file, r_line)) {
            map[i][110] = '\0'; 
            std::copy(r_line.begin(), r_line.end(), map[i++]);
        }
        read_file.close();
    }
    
    updatePlayerMap();
    int count_spawn_engimon_liar = 0;

    bool isProcessingCommand = false;
    updateEngimonWildMap();
    showMap();
    skill();
    do {
        if (!isProcessingCommand) std::cout << "=> ";
        isProcessingCommand = false;
        std::cin >> command;
        full_command += command;
        if (command == "w" || command == "a" || command == "s" || command == "d") {
            full_command = "";
            int x = player.getX();
            int y = player.getY();
            if (command == "w") {
                Coordinate coordinate(x, y-1);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    updateMap(engimon_player.getX(), engimon_player.getY());
                    player.MoveUp();
                    updatePlayerMap();
                }
            } else if (command == "a") {
                Coordinate coordinate(x-2, y);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    updateMap(engimon_player.getX(), engimon_player.getY());
                    player.MoveLeft();
                    updatePlayerMap();
                }
            } else if (command == "s") {
                Coordinate coordinate(x, y+1);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    updateMap(engimon_player.getX(), engimon_player.getY());
                    player.MoveDown();
                    updatePlayerMap();
                }
            } else if (command == "d") {
                Coordinate coordinate(x+2, y);
                if (!Player::isCollision(coordinate)) {
                    updateMap(x, y);
                    updateMap(engimon_player.getX(), engimon_player.getY());
                    player.MoveRight();
                    updatePlayerMap();
                }
            }
        }
        else if (command == "view") {
            // std::cout << full_command << '\n';
            if (full_command.length() > 40) {
                full_command = "";
                isProcessingCommand = false;
            } else {
                isProcessingCommand = true;
            }
            continue;
        } else if (command == "engimon") {
            if (full_command.length() > 40) {
                full_command = "";
                isProcessingCommand = false;
            } else {
                isProcessingCommand = true;
            }
            // std::cout << full_command << '\n';
            continue;
        } else if (full_command == "viewengimonliar") {
            // std::cout << full_command << '\n';
            full_command = "";
            viewAllEngimonWild();
            continue;
        } else if (full_command == "viewengimonliar") {
            // std::cout << full_command << '\n';
            full_command = "";
            viewAllEngimonPlayer();
            continue;
//        } else if(full_command == "learn"){
//            full_command = "";
//            learn();
//            continue;
        }else {
            full_command = "";
            continue;
        }

        moveEngimonLiar();

        if (count_spawn_engimon_liar % 15 == 0) {
            EngimonWild *engimon = new EngimonWild();
            engimon_liar.push_back(engimon);
        }
        count_spawn_engimon_liar++;
        engimon_player = *EngimonPlayer::getEngimonActive();

        std::cout << "\n\n";



        updateEngimonWildMap();
        showMap();
        // std::cout << "=> ";

    } while (command != "q");

    for (int i=0; i < engimon_liar.size(); i++) {
        delete engimon_liar[i];
    }
    
    return 0;
}
// showing the map
void showMap() {
    std::cout << 
    "x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x\n" <<
    "x                                                                             x\n" << 
    "x                               Engimon Factory                               x\n" <<
    "x                                                                             x\n"; 
    // std::string x = "x - - - - - - - - - - - - - - - - - o o o o o o o o o o o o o o o o o o o o o x     L/l: Fire/Electric engimon";
    // std::cout << x.length() << '\n';
    for (int i=0; i < 30; i++) {
        std::cout << map[i] << '\n';
    }
    std::cout << "Player: (" << player.getX() << ',' << player.getY() << ")\n";
}

// update map coordinate after object move
void updateMap(int x, int y) {
    if (x <= 34) {
        map[y][x] = '-';
    } else if (x >= 36) {
        if (y <= 15) {
            map[y][x] = 'o';
        } else {
            map[y][x] = '-';
        }
    }
}

// write engimonwild in map 
void updateEngimonWildMap() {
    for (int i=0; i < engimon_liar.size(); i++) {
        updateEngimonMap(*engimon_liar[i]);
    }
}

// write player in map
void updatePlayerMap() {
    map[player.getY()][player.getX()] = 'P';
    updateEngimonMap(engimon_player);
}

void updateEngimonMap(Engimon engimon) {
    int x = engimon.getX(), y = engimon.getY();
    switch (engimon.getElementType()) {
        case Water:
            map[y][x] = 'W';
            break;
        case Ice:
            map[y][x] = 'I';
            break;
        case Fire:
            map[y][x] = 'F';
            break;
        case Ground:
            map[y][x] = 'G';
            break;
        case Electric:
            map[y][x] = 'E';
            break;
        case Fire_Electric:
            map[y][x] = 'L';
            break;
        case Water_Ice:
            map[y][x] = 'S';
            break;
        case Water_Ground:
            map[y][x] = 'N';
            break;
    }
    if(engimon.getLevel() < 20) {
        map[y][x] += -'A'+'a'; 
    }
}

// move engimon liar randomly
void moveEngimonLiar() {
    for (int i=0; i < engimon_liar.size(); i++) {
        bool isMove = false;
        do {
            int move = std::rand() % 4;
            switch (move) {
                // move right
                case 0: {
                    Coordinate coordinate(engimon_liar[i]->getX() + 2, engimon_liar[i]->getY());
                    if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                        updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                        engimon_liar[i]->MoveRight();
                        isMove = true;
                    }
                    break;
                }
                // move down
                case 1: {
                    Coordinate coordinate(engimon_liar[i]->getX(), engimon_liar[i]->getY()+1);
                    if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                        updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                        engimon_liar[i]->MoveDown();
                        isMove = true;
                    }
                    break;
                }
                // move left
                case 2: {
                    Coordinate coordinate(engimon_liar[i]->getX()-2, engimon_liar[i]->getY());
                    if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                        updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                        engimon_liar[i]->MoveLeft();
                        isMove = true;
                    }
                    break;
                }
                // move up
                case 3: {
                    Coordinate coordinate(engimon_liar[i]->getX(), engimon_liar[i]->getY()-1);
                    if (!EngimonWild::isCollision(coordinate) && engimon_liar[i]->isInArea(coordinate)) {
                        updateMap(engimon_liar[i]->getX(), engimon_liar[i]->getY());
                        engimon_liar[i]->MoveUp();
                        isMove = true;
                    }
                    break;
                }
            }
        } while (!isMove);
    }

}

void viewAllEngimonPlayer() {

}

void viewAllEngimonWild() {
    for (int i=0; i < engimon_liar.size(); i++) {
        std::cout << "Coordinate: (" << engimon_liar[i]->getX() << ',';
        std::cout << engimon_liar[i]->getY() << ')' << '\n';
        std::cout << "Level: " << engimon_liar[i]->getLevel() << '\n';
        std::cout << "Element: " << engimon_liar[i]->getElementType() << '\n';
        std::cout << "Active: " << engimon_liar[i]->getActive() << '\n';
    }
}

void skill(){
    //Skill Punch();
    //Punch("Punch", 400, 1, 1, [Fire, Ice, Water, Electric, Ground, Fire_Electric, Water_Ice, Water_Ground]);
    //Skill JudoKick();
    //JudoKick("JudoKick", 400, 1, 1, [Fire, Ice, Water, Electric, Ground, Fire_Electric, Water_Ice, Water_Ground]);
    Skill Fireball("Fireball", 500, 1, 1, Fire);
    Skill Flamethrower("Flamethrower", 600, 1, 1, Fire);
    Skill NuclearHit("NuclearHit", 700, 1, 1, Fire_Electric);
    Skill Wave("Wave", 500, 1, 1, Water);
    Skill Tsunami("Tsunami", 600, 1, 1, Water_Ground);
    Skill Storm("Storm", 700, 1, 1, Water);
    Skill FrostNova("FrostNova", 500, 1, 1, Ice);
    Skill CryogenicFreeze("CryogenicFreeze", 600, 1, 1, Ice);
    Skill IceSpikes("IceSpikes", 700, 1, 1, Water_Ice);
    Skill Earthquake("Earthquake", 500, 1, 1, Ground);
    Skill MeteorStrike("MeteorStrike", 600, 1, 1, Ground);
    Skill Asteroid("Asteroid", 700, 1, 1, Ground);
    Skill Lightning("Lightning", 500, 1, 1, Electric);
    Skill ElectroBall("ElectroBall", 600, 1, 1, Fire_Electric);
    Skill TeslaRay("TeslaRay", 700, 1, 1, Electric);
}

//void learn(){
//    
//}

void battle(int x, int y){
    

    //get enemy ( priority in order : up, right , left ,down)
    bool enemyFound= false;
    int indexEngLiar;
    for (int j=0; j < engimon_liar.size(); j++) {
        
        if (engimon_liar[j]->getX()==x+2 && engimon_liar[j]->getY()==y+1){
            indexEngLiar=j;
            enemyFound= true;
            break;
        } else if (engimon_liar[j]->getX()==x+2 && engimon_liar[j]->getY()==y){
            indexEngLiar=j;
            enemyFound= true;
            break;
        } else if (engimon_liar[j]->getX()==x && engimon_liar[j]->getY()==y-1){
            indexEngLiar=j;
            enemyFound= true;
            break;
        } else if (engimon_liar[j]->getX()==x-2&& engimon_liar[j]->getY()==y){
            indexEngLiar=j;
            enemyFound= true;
            break;
        }
    }

    if (enemyFound){
        // mungkin jadi engimon_payer[indexEngPlayer].duel(engimon_liar[indexEngLiar])
        bool win=duel(engimon_player,engimon_liar[indexEngLiar]);
        if (win){ // engimon player win
            /*
            if (count_inventory < max_inventory) {
                //Add engimon liar to engimon player 
                EngimonPlayer *newEngPlayer = new EngimonPlayer();
                engimon_player.push_back(newEngPlayer);
                count_inventory ++;

                //get skill item from engimon liar SKILL ITEM nanti aja mungkin
                if (count_inventory < max_inventory) {
                    //Copy engimon_liar terus bikin EngimonPlayer *engimonp = new EngimonPlayer();
                    //Skill skillenemy = new Skill();
                    //inventory.Add(skillenemy); or push_back ?
                    count_inventory ++;
                }

            delete engimon_liar[indexEngLiar];  
            */  
        }
        else {
            /*
            // lose , delete engimon_player
            delete engimon_player[indexEngPlayer];
            count_inventory --;
            */
        }
    } 
    else {
         std::cout<<"Enemy not found\n";
    }
}

bool duel(EngimonPlayer engPlayer, EngimonWild* engLiar){

    float multiplierEngPlayer = compareElement(engPlayer.getElementType(),engLiar->getElementType());
    int sumTotalSkillPowerEngPlayer= engPlayer.sumTotalSkillPower();
    float totalPowerEngPlayer = engPlayer.getLevel()*multiplierEngPlayer +sumTotalSkillPowerEngPlayer;
    
    float multiplierEngLiar = compareElement(engLiar->getElementType(),engPlayer.getElementType());
    int sumTotalSkillPoweEngLiar= engLiar->sumTotalSkillPower();
    float totalPowerEngLiar = engLiar->getLevel()*multiplierEngLiar +sumTotalSkillPoweEngLiar;
    
    if (totalPowerEngPlayer>=totalPowerEngLiar){// if draw then assumed win
        std::cout<<"You win the battle\n";
        return true;
    }
    else {
        std::cout<<"You lose the battle\n";
        return false;
    }
}

void breed(EngimonPlayer engParentA,EngimonPlayer engParentB){

    
        if (engParentA.getLevel()>=30 && engParentB.getLevel()>=30 ){
            
            // Get ElementType and species from parents
            ElementType elementEngParentA=engParentA.getElementType();
            std::string speciesEngParentA=engParentA.getSpecies();

            ElementType elementEngParentB=engParentB.getElementType ();
            std::string speciesEngParentB=engParentB.getSpecies();

            ElementType elementChild;
            std::string speciesChild;
            
            getElementSpeciesChild(elementEngParentA,speciesEngParentA,
                                    elementEngParentB,speciesEngParentB,
                                    &elementChild,&speciesChild);
            
            //Get skills from parents
            
            Skill listSkillEngParentA= engParentA.getSkill();
            Skill listSkillEngParentB= engParentB.getSkill();

            Skill listSkillChild; 
            getListSkillChild(listSkillEngParentA,listSkillEngParentB,listSkillChild,elementChild);
            

            //Get child name
            /*
            std::string nameChild;
            std::cout<<"Ketik nama dari child Engimon: \n";
            std::cin>>nameChild;
            */
            //Create child 

            //EngimonPlayer* child= new EngimonPlayer(speciesChild,elementChild,listSkillChild);
            //engimon_player.push_back(child);

            std::cout<<"Child created\n";
            /*
            EngimonPlayer* child= new EngimonPlayer(engParentA.getName(),speciesEngParentA,
            engParentB.getName(),speciesEngParentB,nameChild,speciesChild,elementChild,listSkillChild);
            engimon_player.push_back(child);*/
            //Decrease parent level
            engParentA.setLevel(engParentA.getLevel()-30);
            engParentB.setLevel(engParentB.getLevel()-30);
        }
        else {
            std::cout<<"Level parent tidak cukup";
        }
}
// masukin di engimonplayer.h



void getElementSpeciesChild(ElementType elementEngParentA,std::string speciesEngParentA,
                            ElementType elementEngParentB,std::string speciesEngParentB,
                            ElementType* elementChild,std::string *speciesChild){
    //get species child &  ElementType child 
    int randomhalf = std::rand() %2 ;
    bool isParentADual=false;
    bool isParentBDual=false;
    ElementType getElement;
    std::string getSpecies;
    if (elementEngParentA ==Fire_Electric ||elementEngParentA ==Water_Ice ||elementEngParentA ==Water_Ground ){
        isParentADual=true;
    }
    if (elementEngParentB ==Fire_Electric ||elementEngParentB ==Water_Ice ||elementEngParentB ==Water_Ground){
        isParentBDual=false;
    }
    if (elementEngParentA==elementEngParentB){
        //parent A= ElementType parent B=ElementType child 
        // species child random from A or B
        switch (randomhalf){
            case 0 :
                getSpecies=speciesEngParentA; break;
            case 1 :
                getSpecies=speciesEngParentB; break;
        }
        getElement=elementEngParentA;
    }
    else {// A & B different element

        //get elemental advantage of parent A & B
        float multiplierParentA= compareElement(elementEngParentA,elementEngParentB);
        float multiplierParentB= compareElement(elementEngParentA,elementEngParentB);
        
        if (multiplierParentA>multiplierParentB){
            getElement=elementEngParentA;
            getSpecies=speciesEngParentA;
        }
        else if (multiplierParentA<multiplierParentB){
            getElement=elementEngParentB;
            getSpecies=speciesEngParentB;
        }
        else {// A & B equal ElementType advantage
            
            // parent A or B is dual ElementType or both A & B is dual element
            // ElementType child & species child random from ElementType parent A or B
            if (isParentADual||isParentBDual){
                if (isParentADual&&isParentBDual){
                    // breed is either fire electric x water ground or fire electric x water ice
                    // possible child  ElementType : fire,electric,fire electric , water,ground,ice,water_ground, water_ice
                    // if ElementType child is fire,electric ,water,ground, ice, species child is random
                    // if fire_electric , species child is parent with fire_electric element
                    // if water_ground, species child is parent with water_ground element
                    // if water_ice, species child is parent with water_ice element
                    //int randomsix= std::rand() % 6;
                    switch(randomhalf){
                        // case 0: 
                        //     getElement=Fire;
                        //     getSpecies=getElement.getRandomSpeciesFromElement();
                        //     break;
                        // case 1: 
                        //     getElement=Electric;
                        //     getSpecies=getElement.getRandomSpeciesFromElement();
                        //     break;
                        case 0: 
                            getElement=Fire_Electric;
                            if (elementEngParentA==Fire_Electric){
                                getSpecies=speciesEngParentA;
                            } else {
                                getSpecies=speciesEngParentB;
                            }
                            break;
                        // case 3: 
                        //     getElement=Water;
                        //     getSpecies=getElement.getRandomSpeciesFromElement();
                        //     break;
                        case 1: 
                            if (elementEngParentA==Water_Ground||elementEngParentB==Water_Ground){
                                getElement=Water_Ground;
                            }else if (elementEngParentA==Water_Ice||elementEngParentB==Water_Ice){
                                getElement=Water_Ice;
                            }
                            if (elementEngParentA==Water_Ground||elementEngParentA==Water_Ice){
                                getSpecies=speciesEngParentA;
                            } else {
                                getSpecies=speciesEngParentB;
                            }
                            break;
                        // case 5: 
                        //     if (elementEngParentA==Water_Ground||elementEngParentB==Water_Ground){
                        //         getElement=Ground;
                        //     }else if (elementEngParentA==Water_Ice||elementEngParentB==Water_Ice){
                        //         getElement=Ice;
                        //     }
                        //     getSpecies=getElement.getRandomSpeciesFromElement();
                        //     break;
                    } 
                    
                }
                else {
                    // breed is single ElementType x dual element
                    switch (randomhalf){
                    case 0 :
                        getElement=elementEngParentA; getSpecies=speciesEngParentA; break;
                    case 1 :
                        getElement=elementEngParentB; getSpecies=speciesEngParentB; break;
                    }
                }
            }
            else {
                // breed single ElementType x single element
                // both parent's ElementType advantage is equal 
                // breed is either fire x electric , water x ground , water x ice
                // child ElementType is dual element
                // child species get random with compatible dual element
                switch(elementEngParentA){
                    case Fire :
                    if (elementEngParentB==Electric){
                        getElement=Fire_Electric;
                    } 
                    break;
                    case Water :
                    if (elementEngParentB==Ground){
                        getElement=Water_Ground;
                    } 
                    else {
                        getElement=Water_Ice;
                    }
                    break;
                    case Electric :
                    if (elementEngParentB==Fire){
                        getElement=Fire_Electric;
                    } 
                    break;
                    case Ground :
                    if (elementEngParentB==Water){
                        getElement=Water_Ground;
                    } 
                    break;
                    case Ice :
                    if (elementEngParentB==Water){
                        getElement=Water_Ice;
                    } 
                    break;
                }
                switch(randomhalf){
                    case 0:{
                        getSpecies=speciesEngParentA;
                    }
                    case 1:{
                        getSpecies=speciesEngParentB;
                    }
                }
                //get species random if fire x electric , water x ground , water x ice
                //getSpecies=getElement.getRandomSpeciesFromElement());
            }
        
        }
    }
    *speciesChild=getSpecies;
    *elementChild=getElement;
}


void getListSkillChild(Skill listSkillEngParentA, Skill listSkillEngParentB, Skill listSkillChild,ElementType elementChild){

    /*
    int indexEngParentA=0;            
    int indexEngParentB=0;*/

    // set skill child to skill parent A[0], possibly not compatible with ElementType child
    Skill skillChild=listSkillEngParentA;
    if (!isSkillCompatibleElement(skillChild,elementChild)){
        skillChild=listSkillEngParentB;
    }
    
    // bool fromparentA = true; //  is true if from parent A

    // int counter=0;
    // //iterasi parent A for skill compatible with ElementType child
    // // until found compatible skill or until >parent A skill size
    // while(!isSkillCompatibleElement(skillChild,elementChild) || listSkillEngParentA.size()<counter){
    //     skillChild=listSkillEngParentA[counter];
    //     counter++;
    // }

    // counter=0;
    // //iterasi parent B for skill compatible with element
    // // until found compatible skill or until >parent B skill size
    // while(!isSkillCompatibleElement(skillChild,elementChild) || listSkillEngParentB.size()<counter){
    //     skillChild=listSkillEngParentB[counter];
    //     if(isSkillCompatibleElement(skillChild,elementChild)){
    //         fromparentA=false;
    //     }
    //     counter++;
    // }

    
    // counter=0;
    // while (listSkillChild.size()<4 || listSkillEngParentA.size()+listSkillEngParentB.size()<counter){

    //         // Get skill with maximum mastery level
    //         // iteration of list skill parent A
    //         while (indexEngParentA<listSkillEngParentA.size()){
    //             // priority skill parent A if skill level A equal skill level B
    //             if (isSkillCompatibleElement(listSkillEngParentA[indexEngParentA],elementChild) && skillChild.getSkillLevel()<=listSkillEngParentA[indexEngParentA].getSkillLevel()){
    //                 skillChild=listSkillEngParentA[indexEngParentA];
    //                 fromparentA=true;
    //             }
    //                 // iteration of list skill parent B
    //                 while (indexEngParentB<listSkillEngParentB.size()){
                        
    //                     // skill level A[indexEngParentA] < skill level B[indexEngParentB] 
    //                     if (isSkillCompatibleElement(listSkillEngParentB[indexEngParentB],elementChild) && skillChild.getSkillLevel()<listSkillEngParentB[indexEngParentB].getSkillLevel()){
    //                         skillChild=listSkillEngParentB[indexEngParentB];
    //                         fromparentA=false;
    //                     }
    //                     // else skill level A[indexEngParentA] > skill level B[indexEngParentB]
    //                     // else skill level A[indexEngParentA] = skill level B[indexEngParentB]                    
    //                 indexEngParentB++;
    //                 }
    //             indexEngParentA++;
    //         }

    //     if (fromparentA){ //skill from parent A, check list skill B for equal skill names
    //         for (int j=0;j<listSkillEngParentB.size();j++){
    //             // if skill name from parent A is in parent B 
    //             if (skillChild.getSkillName()==listSkillEngParentB[j].getSkillName()){
                    
    //                 // if mastery level A = mastery level B
    //                 if (skillChild.getSkillLevel()==listSkillEngParentB[j].getSkillLevel()){
    //                 skillChild.setSkillLevel(skillChild.getSkillLevel()+1);
    //                 } 
    //                 // if mastery level A < mastery level B
    //                 if (skillChild.getSkillLevel()<listSkillEngParentB[j].getSkillLevel()){
    //                     skillChild.setSkillLevel(listSkillEngParentB[j].getSkillLevel());
    //                 }
    //                 // else (mastery level A > mastery level B)
    //             }
    //         }
    //     } else { // skill is from parent B, check skill list parent A for equal skill names
    //         for (int j=0;j<listSkillEngParentA.size();j++){
    //             // if skill name from parent A is in parent B 
    //             if (skillChild.getSkillName()==listSkillEngParentA[j].getSkillName()){
                    
    //                 // if mastery level A = mastery level B
    //                 if (skillChild.getSkillLevel()==listSkillEngParentA[j].getSkillLevel()){
    //                 skillChild.setSkillLevel(skillChild.getSkillLevel()+1);
    //                 } 
    //                 // if mastery level A < mastery level B
    //                 if (skillChild.getSkillLevel()<listSkillEngParentA[j].getSkillLevel()){
    //                     skillChild.setSkillLevel(listSkillEngParentA[j].getSkillLevel());
    //                 }
    //                 // else (mastery level B > mastery level A)
    //             }
    //         }
    //     }
    //     *listSkillChild.push_back(skillChild);
    //     counter++;
    //}
}
bool isSkillCompatibleElement(Skill skillEngimon,ElementType element){
    bool found =false;
    ElementType elementSkill= skillEngimon.getSkillElement();
    if (elementSkill==element){
        found=true;
    }
    return found;
}

float compareElement(ElementType a, ElementType b){ //b = target
    float mult=0;
    switch(a){
        case Fire : switch(b) {
            case Fire : mult=1; break;
            case Water : mult=0; break;
            case Electric : mult=1; break;
            case Ground : mult=0.5; break;
            case Ice : mult=2; break;
            case Fire_Electric : mult=1; break;
            case Water_Ice : mult=2; break;
            case Water_Ground : mult=0.5; break;
        } break;
        case Water : switch(b) {
            case Fire : mult=2; break;
            case Water : mult=1; break;
            case Electric : mult=0; break;
            case Ground : mult=1; break;
            case Ice : mult=1; break;
            case Fire_Electric : mult=2; break;
            case Water_Ice : mult=1; break;
            case Water_Ground : mult=1; break;
        } break;
        case Electric : switch(b) {
            case Fire : mult=1; break;
            case Water : mult=2; break;
            case Electric : mult=1; break;
            case Ground : mult=0; break;
            case Ice : mult=1.5; break;
            case Fire_Electric : mult=1; break;
            case Water_Ice : mult=2; break;
            case Water_Ground : mult=2; break;
        } break;
        case Ground : switch(b) {
            case Fire : mult=1.5; break;
            case Water : mult=1; break;
            case Electric : mult=2; break;
            case Ground : mult=1; break;
            case Ice : mult=0; break;
            case Fire_Electric : mult=2; break;
            case Water_Ice : mult=1; break;
            case Water_Ground : mult=1; break;
        } break;
        case Ice : switch(b) {
            case Fire : mult=0; break;
            case Water : mult=1; break;
            case Electric : mult=0.5; break;
            case Ground : mult=2; break;
            case Ice : mult=1; break;
            case Fire_Electric : mult=0.5; break;
            case Water_Ice : mult=1; break;
            case Water_Ground : mult=2; break;
        } break;
        case Fire_Electric : switch(b) {
            case Fire : mult=1; break;
            case Water : mult=2; break;
            case Electric : mult=1; break;
            case Ground : mult=0.5; break;
            case Ice : mult=2; break;
            case Fire_Electric : mult=1; break;
            case Water_Ice : mult=2; break;
            case Water_Ground : mult=2; break;
        } break;
        case Water_Ice : switch(b) {
            case Fire : mult=2; break;
            case Water : mult=1; break;
            case Electric : mult=0.5; break;
            case Ground : mult=2; break;
            case Ice : mult=1; break;
            case Fire_Electric : mult=2; break;
            case Water_Ice : mult=1; break;
            case Water_Ground : mult=2; break;
        } break;
        case Water_Ground : switch(b) {
            case Fire : mult=2; break;
            case Water : mult=1; break;
            case Electric : mult=2; break;
            case Ground : mult=1; break;
            case Ice : mult=1; break;
            case Fire_Electric : mult=2; break;
            case Water_Ice : mult=1; break;
            case Water_Ground : mult=1; break;
        } break;
    }
    return mult;
}