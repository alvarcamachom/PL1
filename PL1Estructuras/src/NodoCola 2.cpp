#include "NodoCola.h"
#include <string>
#include "Vehiculo.h"

using namespace std;

NodoCola::NodoCola()
{
    v=Vehiculo();
    siguiente=NULL;
    //constructor por defecto
}

NodoCola::NodoCola(Vehiculo veh, NodoCola *sig)
{
    v = veh;
    siguiente=sig;
    //constructor 2
}

NodoCola::~NodoCola()
{
    //dtor
}
