#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <string>
#include <iostream>
using namespace std;

enum ElementType {
    Water,
    Ice,
    Fire,
    Ground,
    Electric,
    Fire_Electric,
    Water_Ice,
    Water_Ground
};

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


class Element {
public:
  Element();
  Element(ElementType type);

  operator ElementType() const;
   bool operator == (Element el) const ;
   bool operator != (Element el) const ;
   bool operator == (ElementType elType) const ;
   bool operator != (ElementType elType) const ;
  
  //string getTypeName();
  
  float multiplierTargetElement(Element b);
  

private:
  ElementType type;
};


#endif

//usage example

// Element el1 = Element(Fire);
// cout<<"el1"<<elementNames[el1]<<endl;
// Element el2 = el1;
// el1 = Electric;
// float mult = el1.multiplierTargetElement(el2);
// if (el1==Electric){ cout<<"element electric"<<endl;}
// cout<<"el2"<<el2<<endl;

// will print 
// el1Fire
// element electric
// el22