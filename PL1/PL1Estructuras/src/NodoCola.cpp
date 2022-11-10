#include "NodoCola.h"
#include <string>
#include "Vehiculo.h"

using namespace std;

NodoCola::NodoCola()
{
    siguiente=NULL;
    //constructor por defecto
}

NodoCola::NodoCola(Vehiculo v, NodoCola *sig)
{
    siguiente=sig;
    //constructor 2
}

NodoCola::~NodoCola()
{
    //dtor
}
