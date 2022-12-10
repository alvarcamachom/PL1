#include "Pedido.h"


Pedido::Pedido()
{
    tipo = Pedido::tipoRand();
    modelo = Pedido::modeloRand();
    color = Pedido::colorRand();
    //Faltan zona y concesionario
}

Pedido::~Pedido()
{
    //dtor
}

string Pedido::modeloRand()
{
    string modelos[5] = {"M1","M2","M3","M4","M5"};
    int s = rand()%5;
    string modelo = modelos[s]; //elegimos elemento aleatorio s de la lista
    return modelo;
}

string Pedido::colorRand()
{
    string colores[3] = {"C1","C2","C3"};
    int t = rand()%3;
    string color = colores[t];
    return color;
}

string Pedido::tipoRand()
{
    string tipos[2] = {"N","P"}; //N == Normal ; P==Prioritario
    int r = rand()%2;
    string tipo = tipos[r];
    return tipo;
}



string Pedido::getColor()
{
    return color;
}

string Pedido::getModelo()
{
    return modelo;
}

string Pedido::getTipo()
{
    return tipo;
}

string Pedido::getZona()
{
    return zona;
}

int Pedido::getConcesionario()
{
    return concesionario;
}
