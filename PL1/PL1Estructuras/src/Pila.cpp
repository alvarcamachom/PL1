#include "Pila.h"

using namespace std;

Pila::Pila()
{
    cima = NULL;
}

bool Pila::esVacia()
{
    return cima == NULL;
}

void Pila::apilar(Vehiculo v)
{
    pnodo nuevo = new NodoPila(v,cima);
    //comienzo de la pila nevo nodo
    cima = nuevo;
}

void Pila::desapilar()
{
    pnodo nodo; //puntero aux para manipular el nodo
    if(cima)
    {
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
}

Vehiculo Pila::mostrar() //Es parcial, No usar con pila vacia ya que no devuelve nada y da error.
{
    if (esVacia()){cout<<"Error. Pila vacia. No llamar a la funcion."<<endl;} //Las tildes se ven mal en la consola
    else{return cima->vehiculo;}
}

//destructor
Pila::~Pila()
{
    while(cima)
        desapilar();
}

