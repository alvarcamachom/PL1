#include "Pila.h"

using namespace std;

Pila::Pila()
{
    cima = NULL;
    profundidad = 0;
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
    profundidad++;
}

void Pila::desapilar()
{
    pnodo nodo; //puntero aux para manipular el nodo
    if(cima)
    {
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
        profundidad--;
    }
}

int Pila::get_profundidad()
{
    return profundidad;
}

Vehiculo Pila::mostrar() //Es parcial, No usar con pila vacia ya que no devuelve nada y da error.
{
    if (esVacia()){cout<<"Error. Pila vacia. No llamar a la funcion."<<endl;} //Las tildes se ven mal en la consola
    else{return cima->vehiculo;}
}

void Pila::verPila(){
    NodoPila *aux=cima;
    if(esVacia()){
        cout<<"Camion vacio \n";
    }
    else{
            cout<<"";
    for (int i=0; i<profundidad;i++){
        cout<<"Vehiculo "<<i<<": ";
        cout<<aux->vehiculo.verVehiculo()<<"\n";
        aux=aux->siguiente;
    }

    }

}

//destructor
Pila::~Pila()
{
    while(cima)
        desapilar();
}

