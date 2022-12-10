#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Vehiculo.h"
#include <iostream>

using namespace std;

class NodoLista
{
 friend class Lista;
private:
	NodoLista *siguiente;
	Vehiculo v;
public:
    NodoLista();
	NodoLista(Vehiculo v, NodoLista *sig = NULL);
	~NodoLista();


};

#endif // NODOLISTA_H

