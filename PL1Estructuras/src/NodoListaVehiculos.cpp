#include "NodoListaVehiculos.h"
#include "Vehiculo.h"

NodoListaVehiculos::NodoListaVehiculos()
{
    v = Vehiculo();
    siguiente=NULL;
    //constructor por defecto
}

NodoListaVehiculos::NodoListaVehiculos(Vehiculo veh, NodoListaVehiculos *sig)
	{
            v = veh;
            siguiente = sig;

    }
NodoListaVehiculos::~NodoListaVehiculos()
{
    //dtor
}
