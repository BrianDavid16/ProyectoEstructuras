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
    void setNombre_base(const std::string&);
    void setTam(const int&);
    void setMisImagenes(const std::vector<imagen>&);
    std::string getNombre_base()const;
    unsigned int getTam()const;
    std::vector<imagen> getMisImagenes()const;
    void cargar_volumen(imagen&);
protected:
    std::string nombre_base;
    unsigned int tam; //maximo 99
    std::vector<imagen> MisImagenes;
};
#endif // VOLUMEN_H_INCLUDED
