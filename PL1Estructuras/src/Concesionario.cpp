#include "Concesionario.h"
using namespace std;

Concesionario::Concesionario()
{
    //ctor
}

Concesionario::Concesionario(int num, int zon, ListaVehiculos vConc)
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

ListaVehiculos Concesionario::getVehiculos()
{
    return vehiculosConcesionario;
}
string Concesionario::verConcesionario()
{
    cout<<"Concesionario: " <<getNumero()<<", zona: "<<getZona()<<", con vehiculos: "<<endl;
    getVehiculos().mostrar();
}

Concesionario::~Concesionario()
{
    //dtor
}
