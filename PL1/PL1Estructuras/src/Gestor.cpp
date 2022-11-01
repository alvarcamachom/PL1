#include "Gestor.h"
#include <time.h>

using namespace std;

Gestor::Gestor()
{
    //ctor
}

string Gestor::generarBastidorRand(){
    srand(time(NULL));
    string bastidor = "";
    string letras="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i<5; i++){ //generamos las 5 letras aleatorias
        int r = rand()%26;
        bastidor+=letras[r];
    }
    int numeros = rand()%100 +100; //Generamos los 3 numeros aleatorios
    bastidor+=to_string(numeros); //Pasamos los numeros a string y los concatenamos

    return bastidor;
}

string Gestor::modeloRand(){
    srand(time(NULL));
    string modelos[6] = {"Zafira","Octavia","Golf","Astra","Insignia","Polo"};
    int s = rand()%6;
    string modelo = modelos[s]; //elegimos elemento aleatorio s de la lista
    return modelo;
}

string Gestor::colorRand(){
    srand(time(NULL));
    string colores[6] ={"Azul","Verde","Amarillo","Gris","Negro","Blanco"};
    int t = rand()%6;
    string color = colores[t];
    return color;
}

string Gestor::concesionarioRand(){
    srand(time(NULL));
    string concesionarios[4] ={"Norte","Sur","Este","Oeste"};
    int u = rand()%4;
    string concesionario = concesionarios[u];
    return concesionario;
}


Gestor::~Gestor()
{
    //dtor
}
