#ifndef NODOLISTAVEHICULOS_H
#define NODOLISTAVEHICULOS_H
#include "Vehiculo.h"
#include <iostream>

using namespace std;

class NodoListaVehiculos
{
 friend class ListaVehiculos;
private:
	NodoListaVehiculos *siguiente;
	Vehiculo v;
public:
    NodoListaVehiculos();
	NodoListaVehiculos(Vehiculo v, NodoListaVehiculos *sig = NULL);
	~NodoListaVehiculos();


};

#endif // NODOLISTAVEHICULOS_H

