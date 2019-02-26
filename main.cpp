#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>

#include "punto.h"
void tokenizar(const std::string &l);
bool leerArchivo();


int main()
{
    leerArchivo();
}
void tokenizar(const std::string &l)
{
    int count = 0;
    punto p;
    std::string linea=l;
    char *linea_aux = new char[linea.length() + 1];
    strcpy(linea_aux, linea.c_str());
    char* actual;
    char* bandera;
    int rgb;
    while (bandera!=NULL)
    {
        if(linea_aux[0]=='#')
        {
            //comentario, aun no sabemos si lo vamos a guardar o que pex
        }
        else
        {
            actual=strtok(linea_aux," ");
            std::istringstream conv(actual);
            conv >>rgb;
            p.setR(rgb);
            actual=strtok(NULL," ");
            std::istringstream conv1(actual);;
            conv1 >>rgb;
            p.setG(rgb);
            actual=strtok(NULL," ");
            std::istringstream conv2(actual);
            conv2 >>rgb;
            p.setB(rgb);
        }
        bandera=strtok(linea_aux,"\t");
    }
    delete [] linea_aux;
}
bool leerArchivo()
{
    int contador = 0;
    std::string linea;
    std::string formato;
    char* w;
    char* h;
    std::string m;
    std::string coment;
    try
    {
        std::ifstream myfile("prueba.txt");
        if (myfile.is_open())
        {
            getline(myfile, formato);
            getline(myfile, coment);
            if(coment[0]=='#')
            {
                //comentario, aun no sabemos si lo vamos a guardar o que pex
                getline(myfile, coment);
            }
            char *coment_aux = new char[coment.length() + 1];
            strcpy(coment_aux, coment.c_str());
            w=strtok(coment_aux," ");
            h=strtok(NULL," ");
            getline(myfile, m);
            while (getline(myfile, linea))
            {
                tokenizar(linea);
                contador++;
            }
            delete [] coment_aux;
            return true;
        }
        else
        {
            throw 1;
        }

    }
    catch (int A)
    {
        if (A==1)
        {
            std::cout << "Archivo no leido, compruebe nombre y/o ubicacion" << std::endl;
        }
    }
}
