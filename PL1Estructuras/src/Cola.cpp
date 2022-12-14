#include <iostream>
#include "Cola.h"
#include <string>
#include "NodoCola.h"
using namespace std;

Cola::Cola()
{
    primero = NULL; ultimo = NULL;
    longitud=0;
}

void Cola::encolar(Vehiculo v)
{
    NodoCola* nuevo_nodo=new NodoCola(v);
    if(es_vacia())
    {
        primero=nuevo_nodo;
        ultimo=nuevo_nodo;
    }
    else
    {
        ultimo->siguiente=nuevo_nodo;
        ultimo=nuevo_nodo;
    }
    longitud++;
}

Vehiculo Cola::desencolar(){ //Operacion parcial, no usar si es vacia ya que no devuelve.
     if(!es_vacia())
    {
        Vehiculo v =primero->v;
        NodoCola*aux=primero;
        if((primero==ultimo)&&(primero->siguiente==NULL))
        {
            primero=NULL;
            ultimo=NULL;
            aux->siguiente=NULL;
            delete(aux);
        }
        else
        {
            primero=primero->siguiente;
            aux->siguiente=NULL;
            delete(aux);
        }
        longitud--;
        return v;
    }

    }


Vehiculo Cola::inicio()
    { if(!es_vacia())
        { return primero->v;
        }
    }

int Cola::get_longitud()
    { return longitud;
    }


bool Cola::es_vacia()
    { return ((primero == NULL) && (ultimo == NULL));
    }

void Cola::mostrar_cola(){//Muestra los vehiculos en la cola de la fabrica
    NodoCola *aux=primero;
    if(es_vacia())
    {
        cout<<"Almacen vacio"<<endl;
    }
    else
    {
        cout<<""<<endl;
        for(int i=0; i<longitud; i++)
        {
            cout<<"Vehiculo "<<i+1<<endl;
            /*cout<<aux->v.devolverModelo()<<endl;
            cout<<aux->v.devolverColor()<<endl;
            cout<<aux->v.devolverBastidor()<<endl;*/
            cout<<aux->v.verVehiculo()<<endl;
            aux=aux->siguiente;
        }
    }
}


Cola::~Cola()
{
    //dtor
}
