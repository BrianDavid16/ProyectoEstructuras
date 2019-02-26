#ifndef IMAGEN_H_INCLUDED
#define IMAGEN_H_INCLUDED

#include <string>
#include <vector>
#include "punto.h"

class imagen {
public:
    imagen();
protected:
    std::string nombre; //nombre base y dos numeros de posicion
    unsigned int W;
    unsigned int H;
    unsigned int M; //intensidad
    std::vector<std::vector<punto>> Mymatrix;
};
#endif // IMAGEN_H_INCLUDED
