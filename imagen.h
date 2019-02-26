#ifndef IMAGEN_H_INCLUDED
#define IMAGEN_H_INCLUDED

#include <string>
#include <vector>
#include "punto.h"

class imagen {
public:
    imagen();
    void setW(const int&);
    void setH(const int&);
    void setM(const int&);
    unsigned int getM()const;
    unsigned int getW()const;
    unsigned int getH()const;
    void setMyMatrix(const std::vector<std::vector<punto>>&);
    std::vector<std::vector<punto>> getMyMatrix()const;


protected:
    std::string nombre; //nombre base y dos numeros de posicion
    unsigned int W;
    unsigned int H;
    std::vector<std::vector<punto>> Mymatrix;
    unsigned int M; //intensidad
};
#endif // IMAGEN_H_INCLUDED
