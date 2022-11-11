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
concesionario = 0;
}

Vehiculo::Vehiculo(string m, string c, string b, int con)
{
modelo = m;
color = c;
bastidor = b;
concesionario = con;
}

string Vehiculo::devolverModelo(){return modelo;}
string Vehiculo::devolverColor(){return color;}
string Vehiculo::devolverBastidor(){return bastidor;}
int Vehiculo::devolverConcesionario(){return concesionario;}


string Vehiculo::verVehiculo(){
    return("vehiculo: " + devolverModelo() + ", color: " + devolverColor() + ", bastidor: " + devolverBastidor() + ", concesionario: " +"\n");
}
Vehiculo::~Vehiculo()
{
    //dtor
}
