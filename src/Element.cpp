#include "Element.h"

Element::Element(){}
Element::Element(ElementType type) : type(type) { }

Element::operator ElementType() const { return type; }
 bool Element::operator == (Element el) const { return type == el.type; }
 bool Element::operator != (Element el) const { return type != el.type; }    
 bool Element::operator == (ElementType elType) const { return type == elType; }
 bool Element::operator != (ElementType elType) const { return type != elType; }


float Element::multiplierTargetElement(Element b){
  float mult=0;
  switch(type){
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
      default : mult=0;
  }
  return mult;
}