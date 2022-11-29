#include "Pedido.h"

Pedido::Pedido()
{
    //ctor
}

Pedido::~Pedido()
{
    //dtor
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
