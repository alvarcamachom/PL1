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
concesionario = Gestor::concesionarioRand();
}

Vehiculo::Vehiculo(string m, string c, string b, string conc)
{
modelo = m;
color = c;
bastidor = b;
concesionario = conc;
}

string Vehiculo::devolverModelo(){return modelo;}
string Vehiculo::devolverColor(){return color;}
string Vehiculo::devolverBastidor(){return bastidor;}
string Vehiculo::devolverConcesionario(){return concesionario;}

string Vehiculo::verVehiculo(){
    return("El vehiculo es un " + modelo + ", color: " + color + ", con bastidor " + bastidor + ", con concesionario " + concesionario+"\n");
}
Vehiculo::~Vehiculo()
{
    //dtor
}
