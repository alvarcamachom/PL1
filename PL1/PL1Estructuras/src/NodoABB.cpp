#include "NodoABB.h"

NodoABB::NodoABB()
{
    //ctor
}

NodoABB::NodoABB(Vehiculo v, NodoABB *izq, NodoABB *der)
{
    //ctor
    v=v;
    hi=izq;
    hd=der;
}

NodoABB::~NodoABB()
{
    //dtor
}
