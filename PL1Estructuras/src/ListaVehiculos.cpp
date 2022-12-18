#include "ListaVehiculos.h"
#include "NodoListaVehiculos.h"
#include "Vehiculo.h"
using namespace std;
#include <iostream>

ListaVehiculos::ListaVehiculos()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

ListaVehiculos::~ListaVehiculos()
{
}

int ListaVehiculos::get_longitud()
{
    return longitud;
}

void ListaVehiculos::insertar_izquierda(Vehiculo v)
{
    NodoListaVehiculos *nuevo_nodo = new NodoListaVehiculos(v);

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

void ListaVehiculos::insertar_derecha(Vehiculo v)
{
    NodoListaVehiculos *nuevo_nodo = new NodoListaVehiculos(v);

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

void ListaVehiculos::insertar_enPosicion(int posicion, Vehiculo v)
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
            NodoListaVehiculos *aux = primero;
            NodoListaVehiculos *nuevo_nodo = new NodoListaVehiculos(v);

            for(int i = 1; i < posicion-1; i++)
            {
                aux = aux->siguiente;
            }

            nuevo_nodo->siguiente = aux->siguiente;
            aux->siguiente = nuevo_nodo;

            longitud++;
        }
    }
    else
    {
        cout<<"Error, posicion no existe."<<endl;
    }
}

/*void Lista::insertar_prioridad(Vehiculo v)
{
    NodoLista *nuevo_nodo = new NodoLista(p);
    NodoLista *aux = primero;
    if(es_vacia())
    {
        insertar_izquierda(p);
    }
    else if (primero->p.getTipo()=="N")
    {
        insertar_izquierda(p);
    }
    else
    {
        while(aux->siguiente!=NULL&&aux->siguiente->p.getTipo()!="N")
        {
            aux=aux->siguiente;
        }
        nuevo_nodo->siguiente = aux->siguiente;
        aux->siguiente = nuevo_nodo;
        longitud++;

    }

}
*/

Vehiculo ListaVehiculos::ver_primero()
{
    if(!es_vacia())
    {
        return primero->v;
    }
}

Vehiculo ListaVehiculos::ver_ultimo()
{
    if(!es_vacia())
    {
        return ultimo->v;
    }
}

Vehiculo ListaVehiculos::ver_posicion(int posicion)
{
    if(!es_vacia())
    {
        NodoListaVehiculos *aux = primero;

        for(int i = 1; i < posicion; i++)
        {
            aux = aux->siguiente;
        }

        return aux->v;
    }
}

bool ListaVehiculos::es_vacia()
{
    return ((primero == NULL) && (ultimo == NULL));
}

void ListaVehiculos::borrar_izquierda()
{
    if(!es_vacia())
    {
        NodoListaVehiculos *aux = primero;

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


void ListaVehiculos::borrar_posicion(int posicion)
{
    if((posicion<1) || (posicion>longitud)){cout<<"error, posicion inexistente";}
    else if  (es_vacia())
    {
        cout<<"No existe la posicion"<<endl;
    }
    else
    {

        if(posicion == 1)
        {
            borrar_izquierda();
        }

        else
        {
            NodoListaVehiculos *aux = primero;

            for(int i = 1; i <posicion-1; i++)
            {
                aux = aux->siguiente;
            }
            NodoListaVehiculos *borrar=aux->siguiente;
            if (borrar->siguiente==NULL)
            {
                ultimo=aux;
            }

            aux->siguiente = borrar->siguiente;

            borrar->siguiente = NULL;

            delete borrar;
            longitud--;
        }

    }

}

void ListaVehiculos::vaciar_lista()
{
    if(!es_vacia())
    {
        borrar_izquierda();
        return vaciar_lista();
    }
}


void ListaVehiculos::mostrar()
{
    NodoListaVehiculos *aux;

    aux = primero;
    if (es_vacia())
    {
        cout<<"Lista Vacia"<<endl;
    }
    else
    {
        int o=0;
        while(aux)
        {
            o++;
            cout<< "Vehiculo: " <<o <<endl;
            cout << aux->v.verVehiculo();
            aux = aux->siguiente;
        }
        cout << endl;
    }
}
