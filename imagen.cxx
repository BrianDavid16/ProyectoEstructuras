#include "imagen.h"
#include <vector>
imagen::imagen(){}
void imagen::setW(const int& m_W){
  this->W=m_W;
}
void imagen::setH(const int& m_H){
  this->H=m_H;
}
void imagen::setM(const int& m_M){
  this->M=m_M;
}
std::vector<std::vector<punto>> imagen::getMyMatrix()const{
  return this->Mymatrix;
}
void imagen::setMyMatrix(const std::vector<std::vector<punto>>& m_Mymatrix){
  this->Mymatrix=m_Mymatrix;
}
unsigned int imagen::getM()const{
  return this->M;
}
unsigned int imagen::getW()const{
  return this->W;
}
unsigned int imagen::getH()const{
  return this->H;
}
