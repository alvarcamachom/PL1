#include "Lista.h"
#include "NodoLista.h"
#include "Pedido.h"
using namespace std;
#include <iostream>

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Lista::~Lista()
{
}

int Lista::get_longitud()
{
	return longitud;
}

void Lista::insertar_izquierda(Pedido p)
{
	NodoLista *nuevo_nodo = new NodoLista(p);

	if(es_vacia())
	{
		primero = nuevo_nodo;
		ultimo = nuevo_nodo;
		longitud++;
	}
	else
	{
		nuevo_nodo->siguiente = primero;
		primero = nuevo_nodo;
		longitud++;
	}
}

void Lista::insertar_derecha(Pedido p)
{
	NodoLista *nuevo_nodo = new NodoLista(p);

	if(es_vacia())
	{
		primero = nuevo_nodo;
		ultimo = nuevo_nodo;
		longitud++;
	}
	else
	{
		ultimo->siguiente = nuevo_nodo;
		ultimo = nuevo_nodo;
		longitud++;
	}
}

void Lista::insertar_enPosicion(int posicion, Pedido p)
{
	if((posicion >=1) && (posicion <= (longitud + 1)))
	{
		if(posicion == 1)
		{
			insertar_izquierda(p);
		}
		else if(posicion == (longitud + 1))
		{
			insertar_derecha(p);
		}
		else
		{
			NodoLista *aux = primero;
			NodoLista *nuevo_nodo = new NodoLista(p);

			for(int i = 1; i < posicion-1; i++)
			{
				aux = aux->siguiente;
			}

			nuevo_nodo->siguiente = aux->siguiente;
			aux->siguiente = nuevo_nodo;

			longitud++;
		}
	}
	else{cout<<"Error, posicion no existe."<<endl;}
}

Pedido Lista::ver_primero()
{
	if(!es_vacia())
	{
		return primero->p;
	}
}

Pedido Lista::ver_ultimo()
{
	if(!es_vacia())
	{
		return ultimo->p;
	}
}

Pedido Lista::ver_posicion(int posicion)
{
	if(!es_vacia())
	{
		NodoLista *aux = primero;

		for(int i = 1; i < posicion; i++)
		{
			aux = aux->siguiente;
		}

		return aux->p;
	}
}

bool Lista::es_vacia()
{
	return ((primero == NULL) && (ultimo == NULL));
}

void Lista::borrar_izquierda()
{
	if(!es_vacia())
	{
		NodoLista *aux = primero;

		if(longitud == 1)
		{
        	primero = NULL;
			ultimo = NULL;
			delete aux;
			longitud--;
		}
		else
		{
			primero = primero->siguiente;
			aux->siguiente = NULL;
			delete aux;
			longitud--;
		}


	}
}


void Lista::borrar_posicion(int posicion)
{
    //(posicion<1) || (posicion>longitud)
	if  (es_vacia()) {cout<<"No existe la posicion"<<endl;}
	else {

		if(posicion == 1)
		{
            borrar_izquierda();
		}

		else
		{
			NodoLista *aux = primero;

			for(int i = 1; i <posicion-1; i++)
			{
				aux = aux->siguiente;
			}
			NodoLista *borrar=aux->siguiente;
			if (borrar->siguiente==NULL) {ultimo=aux;}

			aux->siguiente = borrar->siguiente;

			borrar->siguiente = NULL;

			delete borrar;
		}

	}
}

void Lista::vaciar_lista()//esto esta bien?
{
	if(!es_vacia())
	{
		borrar_izquierda();
		return vaciar_lista();
	}
}


void Lista::mostrar() {
   NodoLista *aux;

   aux = primero;
   if (es_vacia()) {cout<<"Lista Vacia"<<endl;}
   else {
       int o=0;
   while(aux) {
        o++;
        cout<< "Pedido: " <<o <<endl;
      cout << aux->p.verPedido();
      aux = aux->siguiente;
   }
   cout << endl;
}}

