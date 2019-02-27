#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>

#include "punto.h"
#include "imagen.h"
#include "volumen.h"

int main(){
  imagen ph;
  volumen vol;
  char comando[100];
  char* pch,*cargar_volumen,*n_base,*aux_n;
  int contador=0;
  std::cout<<"ingrese: ";
  std::cin.getline(comando,100);

  pch = strtok (comando," ");
  while (pch != NULL)
  {
    if(contador==0){
      cargar_volumen=pch;
    }
    if(contador==1){
      n_base=pch;
      vol.setNombre_base(n_base);
    }
    if(contador==2){
      aux_n=pch;
      int tam;
      std::istringstream conv(aux_n);
      conv >>tam;
      if(tam<0){
        throw std::runtime_error("La imagen no ha podido cargarse->El tamaño debe ser mayor a 0");
      }
      vol.setTam(tam);
    }
    pch = strtok (NULL, " ");
    contador++;
  }
  if(strcmp(cargar_volumen,"cargar_volumen")==0){
    vol.cargar_volumen(ph);
  }else{
    throw std::runtime_error("Comando invalido");
  }
}
