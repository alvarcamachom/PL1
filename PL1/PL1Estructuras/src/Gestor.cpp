#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"

using namespace std;

Gestor::Gestor()
{
    //ctor
}


string Gestor::generarBastidorRand()
{
    string bastidor = "";
    string letras="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i<5; i++)  //generamos las 5 letras aleatorias
    {
        int r = rand()%26;
        bastidor+=letras[r];
    }
    int numeros = rand()%100 +100; //Generamos los 3 numeros aleatorios
    bastidor+=to_string(numeros); //Pasamos los numeros a string y los concatenamos

    return bastidor;
}

string Gestor::modeloRand()
{
    string modelos[6] = {"Opel Zafira","Skoda Octavia","Volkswagen Golf","Opel Astra","Opel Insignia","Volkswagen Polo"};
    int s = rand()%6;
    string modelo = modelos[s]; //elegimos elemento aleatorio s de la lista
    return modelo;
}

string Gestor::colorRand()
{
    string colores[6] = {"Azul","Verde","Amarillo","Gris","Negro","Blanco"};
    int t = rand()%6;
    string color = colores[t];
    return color;
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
    return rand()%6 +3; //numero aleatorio entre 3 y 8 (vehiculos que salen de fabrica)
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
    if(vehiculosFabrica.es_vacia())
    {
        cout<<"La fabrica esta vacia"<<endl;
    }
    else
    {
        while(!vehiculosFabrica.es_vacia())
        {
            vehiculosFabrica.desencolar();
        }
    }
    cout<<"Se han borrado los vehiculos del almacen"<<endl;
}

Gestor::~Gestor()
{
    //dtor
}
