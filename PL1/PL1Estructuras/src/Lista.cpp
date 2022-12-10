#include "Lista.h"
#include "NodoLista.h"
#include "Vehiculo.h"
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

void Lista::insertar_izquierda(Vehiculo v)
{
	NodoLista *nuevo_nodo = new NodoLista(v);

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

void Lista::insertar_derecha(Vehiculo v)
{
	NodoLista *nuevo_nodo = new NodoLista(v);

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

void Lista::insertar_enPosicion(int posicion, Vehiculo v)
{
	if((posicion >=1) && (posicion <= (longitud + 1)))
	{
		if(posicion == 1)
		{
			insertar_izquierda(v);
		}
		else if(posicion == (longitud + 1))
		{
			insertar_derecha(v);
		}
		else
		{
			NodoLista *aux = primero;
			NodoLista *nuevo_nodo = new NodoLista(v);

			for(int i = 1; i < posicion-1; i++)
			{
				aux = aux->siguiente;
			}

			nuevo_nodo->siguiente = aux->siguiente;
			aux->siguiente = nuevo_nodo;

			longitud++;
		}
	}
}

Vehiculo Lista::ver_primero()
{
	if(!es_vacia())
	{
		return primero->v;
	}
}

Vehiculo Lista::ver_ultimo()
{
	if(!es_vacia())
	{
		return ultimo->v;
	}
}

Vehiculo Lista::ver_posicion(int posicion)
{
	if(!es_vacia())
	{
		NodoLista *aux = primero;

		for(int i = 1; i < posicion; i++)
		{
			aux = aux->siguiente;
		}

		return aux->v;
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
	if  (es_vacia()) {cout<<"No existe la posici—n"<<endl;}
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

void Lista::vaciar_lista()
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
   if (es_vacia()) {cout<<"Lista Vac’a"<<endl;}
   else {
       int o=0;
   while(aux) {
        o++;
        cout<< "Vehiculo " <<o <<endl;
      cout << aux->v.verVehiculo();
      aux = aux->siguiente;
   }
   cout << endl;
}}

