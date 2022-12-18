#include "NodoLista.h"
#include "Pedido.h"

NodoLista::NodoLista()
{
    p = Pedido();
    siguiente=NULL;
    //constructor por defecto
}

NodoLista::NodoLista(Pedido pe, NodoLista *sig)
	{
            p = pe;
            siguiente = sig;

    }
NodoLista::~NodoLista()
{
    //dtor
}
