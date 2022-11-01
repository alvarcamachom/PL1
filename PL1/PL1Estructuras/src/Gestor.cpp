#include "Gestor.h"
#include <time.h>

Gestor::Gestor(){
    //ctor
}

std::string Gestor::generarBastidorRand(){
    srand(time(NULL));
    std::string bastidor = "";
    std::string letras="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i<5; i++){ //generamos las 5 letras aleatorias
        int r = rand()%26;
        bastidor+=letras[r];
    }
    int numeros = rand()%100 +100; //Generamos los 3 numeros aleatorios
    bastidor+=std::to_string(numeros); //Pasamos los numeros a string y los concatenamos

    return bastidor;
}

Gestor::~Gestor()
{
    //dtor
}
