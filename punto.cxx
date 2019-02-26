#include "punto.h"
punto::punto(){}
punto::~punto(){}
punto::punto(unsigned int r, unsigned int g,unsigned int b){
  this->r=r;
  this->g=g;
  this->b=b;
}
unsigned int punto::Getr() const{
  return this->r;
}
unsigned int punto::Getg() const{
  return this->g;
}
unsigned int punto::Getb() const{
  return this->b;
}
void punto::setR(const int& m_r){
  this->r=m_r;
}
void punto::setG(const int& m_g){
  this->g=m_g;
}
void punto::setB(const int& m_b){
  this->b=m_b;
}
