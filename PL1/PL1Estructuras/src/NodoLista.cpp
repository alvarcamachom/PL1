#include "NodoLista.h"
#include "Vehiculo.h"

NodoLista::NodoLista()
{
    v=Vehiculo();
    siguiente=NULL;
    //constructor por defecto
}

NodoLista::NodoLista(Vehiculo veh, NodoLista *sig)
	{
            v = veh;
            siguiente = sig;

    }
NodoLista::~NodoLista()
{
    //dtor
}
