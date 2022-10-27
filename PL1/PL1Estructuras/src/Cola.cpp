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
{ NodoCola *nuevo_nodo = new
    NodoCola(v, nuevo_nodo);
        if(es_vacia())
            { primero = nuevo_nodo;
            ultimo = nuevo_nodo;
            }
        else
            { ultimo->siguiente = nuevo_nodo;
            ultimo = nuevo_nodo;
            }
            longitud++;
}

Vehiculo Cola::desencolar()
    { if(!es_vacia())
        {Vehiculo v = primero->v;
        NodoCola *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL))
            { primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
            }
        else
            { primero = primero->siguiente;
            aux->siguiente = NULL;
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

Vehiculo Cola::fin()
    { if(!es_vacia())
        { return ultimo->v;
        }
    }

int Cola::get_longitud()
    { return longitud;
    }


bool Cola::es_vacia()
    { return ((primero == NULL) && (ultimo == NULL));
    }


Cola::~Cola()
{
    //dtor
}
