#include "Concesionario.h"
using namespace std;

Concesionario::Concesionario()
{
    //ctor
}

Concesionario::Concesionario(int num, int zon, Lista vConc)
{
    numero = num;
    zona = zon;
    vehiculosConcesionario = vConc;
}

int Concesionario::getNumero()
{
    return numero;
}
int Concesionario::getZona()
{
    return zona;
}

Lista Concesionario::getVehiculos()
{
    return vehiculosConcesionario;
}
string Concesionario::verConcesionario()
{
    return ("Concesionario: " + to_string(getNumero()) + ", zona: " + to_string(getZona()) /*+ ", con vehiculos: " + getVehiculos().mostrar()*/ + "\n");
}

Concesionario::~Concesionario()
{
    //dtor
}
