#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"

using namespace std;

Gestor::Gestor()
{
    //ctor
}

int Gestor::generarNC()
{
    return rand()%7 +4; //numero aleatorio entre 4 y 10 (numero concesionarios)
}
int Gestor::generarNV()
{
    return rand()%21 + 10; //numero aleatorio entre 10 y 30 (numero vehiculos)
}
int Gestor::generarNS()
{
    return rand()%6 +3; //numero aleatorio de vehiculos en almacen (vehiculos que salen de fabrica)
}
int Gestor::generarNP()
{
    return rand()%6 +7; //numero aleatorio entre 7 y 12 (numero vehiculos que entran en camion)
}

void Gestor::crearVehiculo(int nv)
{
    for (int i=1; i<=nv; i++)
    {
        vehiculosFabrica.encolar(Vehiculo());//Meter vehiculo en cola
        //cout<<vehiculosFabrica.fin().verVehiculo();
        //cout<<"Vehiculo metido en almacen"<<endl;

        //desactivado el metodo de fin por si nos arrepentimos de quitarlo
    }
}
void Gestor::mostrarVehiculosFabrica() //Muestra los vehiculos en la cola de la fabrica
{
    vehiculosFabrica.mostrar_cola();
}

void Gestor::borrarVehiculosFabrica() //Borrar todos los vehiculos de la cola
{
    if (vehiculosFabrica.es_vacia())
    {
        cout<<"Almacen vacio"<<endl;
    }
    else
    {
        while (!vehiculosFabrica.es_vacia())
        {
            vehiculosFabrica.desencolar();
        }
    }
}

void Gestor::vehiculosAZona(int ns, ZonaReparto zona)
{

    for (int i=1; i<=ns; i++) //sacar vehiculos de almacen y meter en zona ns veces
    {
        Vehiculo veh = vehiculosFabrica.inicio();
        vehiculosZona.encolar(veh);
        vehiculosFabrica.desencolar();
    }
    //ZonaReparto z = ZonaReparto(zona, vehiculosZona);
    /*crear objeto zona de atributos nombre zona y la cola??? no se podria
    pq el unico atributo de zona es el nombre, no sabria como hacerlo*/
}

Gestor::~Gestor()
{
    //dtor
}
