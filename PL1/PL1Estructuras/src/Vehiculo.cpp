#include "Vehiculo.h"
#include <string>
#include <cstddef>

Vehiculo::Vehiculo()
{
modelo = "";
color = "";
bastidor = "";
concesionario = 0;
}

Vehiculo::Vehiculo(std::string m, std::string c, std::string b, int conc)
{
modelo = m;
color = c;
bastidor = b;
concesionario = conc;
}

void Vehiculo::cargarVehiculo(std::string m, std::string c, std::string b, int conc)
{
modelo = m;
color = c;
bastidor = b;
concesionario = conc;
}

std::string Vehiculo::devolverModelo(){return modelo;}
std::string Vehiculo::devolverColor(){return color;}
std::string Vehiculo::devolverBastidor(){return bastidor;}
int Vehiculo::devolverConcesionario(){return concesionario;}

std::string Vehiculo::verVehiculo(){
    return("El vehiculo es un " + modelo + ", color: " + color + ", con bastidor " + bastidor + ", con concesionario " + std::to_string(concesionario)+"\n");
}
Vehiculo::~Vehiculo()
{
    //dtor
}
