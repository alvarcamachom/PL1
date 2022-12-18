#include "ZonaReparto.h"
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"

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

void ZonaReparto::verRegistro()
{
    vehiculosZona.mostrar_cola();

}

void ZonaReparto::meterRegistro(Vehiculo ve)
{
    vehiculosZona.encolar(ve);
}

Vehiculo ZonaReparto::sacarRegistro()
{
    return vehiculosZona.desencolar();
}

void ZonaReparto::verCamion1()
{
    camion1.verPila();
}

void ZonaReparto::verCamion2()
{
    camion2.verPila();
}

bool ZonaReparto::esCamion1Vacio()
{
    return camion1.esVacia();
}

bool ZonaReparto::esCamion2Vacio()
{
    return camion2.esVacia();
}

void ZonaReparto::meterCamion1(Vehiculo ve)
{
    camion1.apilar(ve);
}

void ZonaReparto::meterCamion2(Vehiculo ve)
{
    camion2.apilar(ve);
}

void ZonaReparto::sacarCamion1()
{
    camion1.desapilar();
}

void ZonaReparto::sacarCamion2()
{
    camion2.desapilar();
}

int ZonaReparto::profundidadCamion1()
{
    return camion1.get_profundidad();
}

int ZonaReparto::profundidadCamion2()
{
    return camion2.get_profundidad();
}

Vehiculo ZonaReparto::mostrarCamion1()
{
    return camion1.mostrar();
}

Vehiculo ZonaReparto::mostrarCamion2()
{
    return camion2.mostrar();
}

ZonaReparto::~ZonaReparto()
{
    //dtor
}
