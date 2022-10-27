#include "Pila.h"

Pila::Pila()
{
    cima = NULL;
}

bool Pila::esVacia(){ return cima == NULL; }

void Pila::apilar(Vehiculo v){
    pnodo nuevo = new NodoPila(v,cima);
    //comienzo de la pila nevo nodo
    cima = nuevo;
}

Vehiculo Pila::desapilar(){
    pnodo nodo; //puntero aux para manipular el nodo
    if(cima){
        nodo = cima;
        cima = nodo->siguiente;
        return cima->vehiculo;
        delete nodo;
    }
}

//destructor
Pila::~Pila(){while(cima) desapilar();}

