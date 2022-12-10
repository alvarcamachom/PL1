#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Vehiculo.h"

class Lista
{
private:
    NodoLista * primero;
	NodoLista * ultimo;
	int longitud;
public:
    Lista();
    ~Lista();
    int get_longitud();
	void insertar_derecha(Vehiculo);
	void insertar_izquierda(Vehiculo);
	void insertar_enPosicion(int, Vehiculo);
	bool es_vacia();
	Vehiculo ver_primero();
	Vehiculo ver_ultimo();
	Vehiculo ver_posicion(int);
	void borrar_izquierda();
	void borrar_posicion(int);
	void vaciar_lista();
    void mostrar();

};

#endif // LISTA_H

