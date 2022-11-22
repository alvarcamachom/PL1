#include "ZonaReparto.h"



ZonaReparto::ZonaReparto()
{
    //ctor
}

ZonaReparto::ZonaReparto(string nombreZona)
{
    //ctor parametros
    nombre=nombreZona;
}

string ZonaReparto::getNombre()
{
    return nombre;
}

void ZonaReparto::setNombre(string nom)
{
    nombre=nom;
}

ZonaReparto::~ZonaReparto()
{
    //dtor
}
