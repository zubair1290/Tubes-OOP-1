#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <vector>
#include <iostream>
#include "Skill.h"
#include "EngimonPlayer.h"


template <class E>
class Inventory{
private:
    static int maxCapacity;
    std::vector<E> invent;
    static int countItem;
    // static int jumlah;
public:
    Inventory(){
        std::cout << "Hai" << std::endl;
    }
    ~Inventory(){

    }
    Inventory& operator<<(const E& i){
        if(getJumlah() < maxCapacity){
            invent.push_back(i);
            countItem++;
        }
        return *this;
    }

    static int getCountItem(){
        return countItem;
    }

    static int getJumlah(){
        return Inventory<Skill>::getCountItem() + Inventory<EngimonPlayer>::getCountItem();
    }

    // void getItem(){
    //     std::ostream_iterator<E> output(cout," ");
    //     cout << "isi: ";
    //     std::copy(invent.begin(), invent.end(), output);
    // }
};

template<class E>
int Inventory<E>::maxCapacity = 5;

template<class E>
int Inventory<E>::countItem = 0;

template<>
Inventory<Skill>& Inventory<Skill>::operator<<(const Skill& i){
    bool ada = false;
    for(auto itr = invent.begin(); itr != invent.end(); itr++){
        if(i == *itr){
            ada = true;
            break;
        }
    }
    if(not ada && getJumlah()<maxCapacity){
        invent.push_back(i);
        Inventory<Skill>::countItem++;
    }
    return *this;
}

#endif