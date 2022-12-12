#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Pedido.h"
#include <iostream>

using namespace std;

class NodoLista
{
 friend class Lista;
private:
	NodoLista *siguiente;
	Pedido p;
public:
    NodoLista();
	NodoLista(Pedido p, NodoLista *sig = NULL);
	~NodoLista();


};

#endif // NODOLISTA_H

