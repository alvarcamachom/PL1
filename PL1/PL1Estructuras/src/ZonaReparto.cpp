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

ZonaReparto::~ZonaReparto()
{
    //dtor
}
