#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"

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
    int limite = vehiculosFabrica.get_longitud();
    return rand()%limite; //numero aleatorio hasta el maximo de vehiculos en almacen (vehiculos que salen de fabrica)
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
        cout<<vehiculosFabrica.fin().verVehiculo();
        cout<<"Vehiculo metido en almacen"<<endl;

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

void Gestor::vehiculosAZona(int ns, ZonaReparto zona){

    for (int i=1; i<=ns; i++){//sacar vehiculos de almacen y meter en zona ns veces
        Vehiculo veh = vehiculosFabrica.inicio();
        /*Aqui quiero en cada iteracion ir sacando coche de cola
        almacen y meterlo en la cola de la zona ns veces*/
        cola_zona.encolar(veh);
        vehiculosFabrica.desencolar();
    }

}

Gestor::~Gestor()
{
    //dtor
}
