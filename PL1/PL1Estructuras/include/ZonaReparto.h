#ifndef ZONAREPARTO_H
#define ZONAREPARTO_H
#include "Cola.h"
#include "Pila.h"
using namespace std;

class ZonaReparto
{
public:
    ZonaReparto();
    ZonaReparto(string);
    virtual ~ZonaReparto();
    string getNombre();
    Cola vehiculosZona;
    Pila camion1;
    Pila camion2;
protected:

private:
    string nombre;
};

#endif // ZONAREPARTO_H
