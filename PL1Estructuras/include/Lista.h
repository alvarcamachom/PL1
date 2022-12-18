#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Pedido.h"

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
	void insertar_derecha(Pedido);
	void insertar_izquierda(Pedido);
	void insertar_enPosicion(int, Pedido);
	void insertar_prioridad(Pedido);
	bool es_vacia();
	Pedido ver_primero();
	Pedido ver_ultimo();
	Pedido ver_posicion(int);
	void borrar_izquierda();
	void borrar_posicion(int);
	void vaciar_lista();
    void mostrar();

};

#endif // LISTA_H

