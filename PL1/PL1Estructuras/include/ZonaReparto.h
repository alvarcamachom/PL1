#ifndef ZONAREPARTO_H
#define ZONAREPARTO_H
#include "Cola.h"
using namespace std;

class ZonaReparto
{
public:
    ZonaReparto();
    ZonaReparto(string);
    virtual ~ZonaReparto();
    string getNombre();
protected:

private:
    string nombre;
    Cola vehiculosZona;
};

#endif // ZONAREPARTO_H
