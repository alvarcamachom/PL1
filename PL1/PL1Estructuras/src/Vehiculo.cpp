#include "Vehiculo.h"
#include "Gestor.h"
#include <string>
#include <cstddef>

using namespace std;

Vehiculo::Vehiculo()
{
modelo = Gestor::modeloRand();
color = Gestor::colorRand();
bastidor = Gestor::generarBastidorRand();
}

Vehiculo::Vehiculo(string m, string c, string b)
{
modelo = m;
color = c;
bastidor = b;
}

string Vehiculo::devolverModelo(){return modelo;}
string Vehiculo::devolverColor(){return color;}
string Vehiculo::devolverBastidor(){return bastidor;}


string Vehiculo::verVehiculo(){
    return("vehiculo: " + modelo + ", color: " + color + ", bastidor: " + bastidor +"\n");
}
Vehiculo::~Vehiculo()
{
    //dtor
}
