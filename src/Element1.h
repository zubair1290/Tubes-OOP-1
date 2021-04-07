#ifndef __ELEMENT1_H__
#define __ELEMENT1_H__

#include <string>
#include <iostream>
#include "ElementType.h"

class Element1 {
public:
  Element1();
  Element1(ElementType type);

  operator ElementType() const;
   bool operator == (Element1 el) const ;
   bool operator != (Element1 el) const ;
   bool operator == (ElementType elType) const ;
   bool operator != (ElementType elType) const ;
  
  //string getTypeName();
  
  //float multiplierTargetElement(Element b);
  
  //std::string getRandomSpeciesFromElement();

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