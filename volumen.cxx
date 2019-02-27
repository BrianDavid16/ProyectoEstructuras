#include "volumen.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
volumen::volumen(){}
void volumen::cargar_volumen(imagen &ph){
  this->MisImagenes.resize(this->tam);
  for(int i=0;i<this->tam;i++){
    ph.leerArchivo();
    ph.printImage();
    this->MisImagenes[i]=ph;
    std::string nombre_completo;
    std::string format=".ppm";
    std::string pos = std::to_string(i);
    nombre_completo=this->nombre_base+pos+format;
    this->MisImagenes[i].setNombre(nombre_completo);
    //std::cout<<this->MisImagenes[i].getNombre();
    std::cin.get();
  }
}
void volumen::proyeccion2D (unsigned int pos){
}//toma las imagenes ya cargadas, preguntarle al cucho porque no entiendo
void volumen::setNombre_base(const std::string&l){
  this->nombre_base=l;
}
void volumen::setTam(const int&t){
  this->tam=t;
}
void volumen::setMisImagenes(const std::vector<imagen>&m){
  this->MisImagenes=m;
}
std::string volumen::getNombre_base()const{
  return this->nombre_base;
}
unsigned int volumen::getTam()const{
  return this->tam;
}
std::vector<imagen> volumen::getMisImagenes()const{
  return this->MisImagenes;
}
