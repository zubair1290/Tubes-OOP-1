#ifndef __Inventoryplusplus_H__
#define __Inventoryplusplus_H__

#include <vector>
#include <iostream>
#include "Skill.h"


template <class E>
class Inventoryplusplus{
private:
    E* item;
    int size;
    int countItem;
public:
    Inventoryplusplus();
    Inventoryplusplus(int)
    ~Inventoryplusplus();
    Inventoryplusplus& operator<<(const E&);
    int getCountItem();
    E getItem();
};

// template <>
// class Inventoryplusplus <Skill>{
// private:
//     Skill item;
//     int size;
//     int countItem;
// public:
//     Inventoryplusplus();
//     Inventoryplusplus(int);
//     ~Inventoryplusplus();
//     Inventoryplusplus& operator<<(const Skill&);
//     int getCountItem();
//     Skill getItem();
// };

#endif