#include "Inventoryplusplus.h"

template <class E>
Inventoryplusplus<E>::Inventoryplusplus(): Inventoryplusplus(15){
    item = new E[this->size];
}

template <class E>
Inventoryplusplus<E>::Inventoryplusplus(int _size): size(_size), countItem(0){
    item = new E[this->size];
}

template <class E>
Inventoryplusplus<E>& Inventoryplusplus<E>::operator<<(const E& I){
    this->countItem = this->countItem+1;
    item[this->countItem-1] = I;
    return *this;
}

template <class E>
int Inventoryplusplus<E>::getCountItem(){
    return countItem;
}

template <class E>
E Inventoryplusplus<E>::getItem(){
    return item;
}
// ---------------------------------------Specialization-------------------------------------
// Inventoryplusplus<Skill>::Inventoryplusplus(): Inventoryplusplus(15){
//     item = new Skill[this->size];
// }

// Inventoryplusplus<Skill>::Inventoryplusplus(int _size): size(_size), countItem(0){
//     item = new Skill[this->size];
// }

Inventoryplusplus<Skill>& Inventoryplusplus<Skill>::operator<<(const Skill& I){
    this->countItem = this->countItem+1;
    int i = 0;
    bool ada = false;
    while(i < countItem-1 && not ada){
        if(item[i] == I){
            ada = true;
        }else{
            ada = false;
            i++;
        }
    }
    if(ada){
        item[this->countItem-1] = I;

    }
    return *this;
}

// int Inventoryplusplus<Skill>::getCountItem(){
//     return countItem;
// }

// Skill Inventoryplusplus<Skill>::getItem(){
//     return item;
// }