#include "NodoPila.h"
#include "Vehiculo.h"

using namespace std;

NodoPila::NodoPila()
{
    vehiculo = Vehiculo();
    siguiente = NULL;
    //ctor
}

NodoPila::NodoPila(Vehiculo v, NodoPila *sig)
{
    vehiculo = v;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
    //dtor
}
