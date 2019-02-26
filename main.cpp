#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>

#include "punto.h"
#include "imagen.h"
int main(){

}
int charToInt(char* h){
  int r;
  std::istringstream conv(h);
  conv >>r;
  return r;
}
void tokenizar(const std::string &l, imagen &ph, const int &j){
    int count = 0;
    punto p;
    std::string linea=l;
    char *linea_aux = new char[linea.length() + 1];
    strcpy(linea_aux, linea.c_str());
    char* actual;
    char* bandera;
    std::vector<std::vector<punto>> aux_vector;
    int rgb,i=0;
    while (bandera!=NULL) {
      if(linea_aux[0]=='#'){
        //comentario, aun no sabemos si lo vamos a guardar o que pex
      }
      else{
        aux_vector=ph.getMyMatrix();
        actual=strtok(linea_aux," ");
        rgb=charToInt(actual);
        if((rgb>ph.getM())&&(rgb<0)){
          throw std::runtime_error("Valor invalido para r");
        }
        p.setR(rgb);
        actual=strtok(NULL," ");
        rgb=charToInt(actual);
        if((rgb>ph.getM())&&(rgb<0)){
          throw std::runtime_error("Valor invalido para g");
        }
        p.setG(rgb);
        actual=strtok(NULL," ");
        rgb=charToInt(actual);
        if((rgb>ph.getM())&&(rgb<0)){
          throw std::runtime_error("Valor invalido para b");
        }
        p.setB(rgb);
      }
      bandera=strtok(linea_aux,"\t");
      i++;
      aux_vector[j][i]=p;
      ph.setMyMatrix(aux_vector);
    }
    delete [] linea_aux;
}
bool leerArchivo()
{
    int contador = 0,M,W,H,j=0;
    char* w;
    char* h;
    imagen ph;
    std::string m,coment,linea,formato;
    try
    {
    std::ifstream myfile("prueba.txt");
    if (myfile.is_open()) {
        getline(myfile, formato);
        getline(myfile, coment);
        if(coment[0]=='#'){
        //comentario, aun no sabemos si lo vamos a guardar o que pex
          getline(myfile, coment);
        }
        char *coment_aux = new char[coment.length() + 1];
        strcpy(coment_aux, coment.c_str());
        w=strtok(coment_aux," ");
        W=charToInt(w);
        ph.setW(W);
        h=strtok(NULL," ");
        H=charToInt(h);
        ph.setH(H);
        getline(myfile, m);
        M=std::stoi(m);
        if((M>255)&&(M<0)){
            throw std::runtime_error("Valor invalido para M");
        }
        ph.setM(M);
        while (getline(myfile, linea)) {
            tokenizar(linea,ph,j);
            j++;
        }
        delete [] coment_aux;
        return true;
    }else{
      throw 1;
    }
	catch (int A)
    {
        if (A==1)
        {
            std::cout << "Archivo no leido, compruebe nombre y/o ubicacion" << std::endl;
        }
    }
}

}
