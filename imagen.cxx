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
void imagen::resizeVectors(){
  int aux1,aux2;
  aux1=this->W;
  aux2=this->H;
  this->Mymatrix.resize(aux1,std::vector<punto>(aux2));
}
void imagen::leerArchivo(){
    int contador = 0,M,W,H,i=0;
    char* w;
    char* h;
    imagen ph;
    punto aux_p;
    std::string m,coment,linea,formato;
    char cadena[128];
    try{
        std::ifstream myfile("example.ppm");
        if (myfile.is_open()){
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
            if(W<0){
              throw std::runtime_error("Valor invalido para W");
            }
            this->setW(W);
            h=strtok(NULL," ");
            H=charToInt(h);
            if(H<0){
              throw std::runtime_error("Valor invalido para H");
            }
            this->setH(H);
            this->resizeVectors();
            getline(myfile, m);
            M=std::stoi(m);
            if((M>255)||(M<0)){
              throw std::runtime_error("Valor invalido para M");
            }
            this->setM(M);
            while ((!myfile.eof())&&(i<this->getW())){
              for(int j=0;j<this->getH();j++){
                myfile >> cadena;
                aux_p.setR(charToInt(cadena));
                myfile >> cadena;
                aux_p.setG(charToInt(cadena));
                myfile >> cadena;
                aux_p.setB(charToInt(cadena));
                if((aux_p.Getr()>this->getM())||(aux_p.Getg()>this->getM())||(aux_p.Getb()>this->getM())){
                  throw std::runtime_error("Valor invalido para los puntos");
                }
                this->Mymatrix[i][j]=aux_p;
                contador=contador+3;
              }
              i++;
            }
        }
        else{
          throw 1;
        }
        if(contador!=(this->getH())*(this->getW())*(3)){
          throw std::runtime_error("La imagen no ha podido cargarse-> La cantidad de valores es invalida");
        }
    }
    catch (int A)
    {
        if (A==1){
            std::cout << "Archivo no leido, compruebe nombre y/o ubicacion" << std::endl;
        }
    }
}
void imagen::setNombre(const std::string&n){
  this->nombre=n;
}
std::string imagen::getNombre()const{
  return this->nombre;
}
int imagen::charToInt(char* h){
  int r;
  std::istringstream conv(h);
  conv >>r;
  return r;
}
void imagen::printImage(){
  for(int i=0;i<this->getW();i++){
    for (int j = 0; j < this->getH(); j++) {
      std::cout<<"["<<i<<"]"<<"["<<j<<"]"<<"{"<<this->Mymatrix[i][j].Getr()<<" , "<<this->Mymatrix[i][j].Getg()<<" , "<<this->Mymatrix[i][j].Getb()<<"}"<<std::endl;
    }
  }
}
