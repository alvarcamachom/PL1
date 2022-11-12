#include "Vehiculo.h"
#include "Gestor.h"
#include <string>
#include <cstddef>

using namespace std;

Vehiculo::Vehiculo()
{
    modelo = Vehiculo::modeloRand();
    color = Vehiculo::colorRand();
    bastidor = Vehiculo::generarBastidorRand();
    concesionario = 0;
}

Vehiculo::Vehiculo(string m, string c, string b, int con)
{
    modelo = m;
    color = c;
    bastidor = b;
    concesionario = con;
}

string Vehiculo::generarBastidorRand()
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

string Vehiculo::modeloRand()
{
    string modelos[6] = {"Opel Zafira","Skoda Octavia","Volkswagen Golf","Opel Astra","Opel Insignia","Volkswagen Polo"};
    int s = rand()%6;
    string modelo = modelos[s]; //elegimos elemento aleatorio s de la lista
    return modelo;
}

string Vehiculo::colorRand()
{
    string colores[6] = {"Azul","Verde","Amarillo","Gris","Negro","Blanco"};
    int t = rand()%6;
    string color = colores[t];
    return color;
}

void Vehiculo::set_concesionario(int n){
    concesionario=n;
}

string Vehiculo::devolverModelo()
{
    return modelo;
}
string Vehiculo::devolverColor()
{
    return color;
}
string Vehiculo::devolverBastidor()
{
    return bastidor;
}
int Vehiculo::devolverConcesionario()
{
    return concesionario;
}


string Vehiculo::verVehiculo()
{
    return("Vehiculo: " + devolverModelo() + ", color: " + devolverColor() + ", bastidor: " + devolverBastidor() + ", concesionario: " + to_string(devolverConcesionario()) + "\n");
}

Vehiculo::~Vehiculo()
{
    //dtor
}
