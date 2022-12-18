#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H
#include "NodoListaVehiculos.h"
#include "Vehiculo.h"

class ListaVehiculos
{
private:
    NodoListaVehiculos * primero;
	NodoListaVehiculos * ultimo;
	int longitud;
public:
    ListaVehiculos();
    ~ListaVehiculos();
    int get_longitud();
	void insertar_derecha(Vehiculo);
	void insertar_izquierda(Vehiculo);
	void insertar_enPosicion(int, Vehiculo);
	//void insertar_prioridad(Pedido);
	bool es_vacia();
	Vehiculo ver_primero();
	Vehiculo ver_ultimo();
	Vehiculo ver_posicion(int);
	void borrar_izquierda();
	void borrar_posicion(int);
	void vaciar_lista();
    void mostrar();

};

#endif // LISTAVEHICULOS_H
