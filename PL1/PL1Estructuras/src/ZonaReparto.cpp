#include "ZonaReparto.h"



ZonaReparto::ZonaReparto()
{
    //ctor
}

ZonaReparto::ZonaReparto(string nombreZona)
{
    //ctor
    nombre=nombreZona;
}

string ZonaReparto::getNombre(){
    return nombre;
}

ZonaReparto::~ZonaReparto()
{
    //dtor
}
