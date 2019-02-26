#ifndef VOLUMEN_H_INCLUDED
#define VOLUMEN_H_INCLUDED
#include <string>
#include <vector>
#include "imagen.h"
class volumen{
public:
    volumen();
    void cargar_volumen(unsigned int n,std::vector<imagen> );
    void proyeccion2D (unsigned int pos);//toma las imagenes ya cargadas, preguntarle al cucho porque no entiendo

protected:
    std::string nombre_base;
    unsigned int tam; //maximo 99
    std::vector<imagen> MisImagenes;
};
#endif // VOLUMEN_H_INCLUDED
