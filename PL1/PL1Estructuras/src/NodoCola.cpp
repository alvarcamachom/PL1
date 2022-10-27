#include "NodoCola.h"
#include <string>
#include "Vehiculo.h"

NodoCola::NodoCola()
{
    v = Vehiculo();
    siguiente=NULL;
    //constructor por defecto
}

NodoCola::NodoCola(Vehiculo v, NodoCola *sig)
{
    v = Vehiculo();
    siguiente=sig;
    //constructor 2
}

NodoCola::~NodoCola()
{
    //dtor
}
