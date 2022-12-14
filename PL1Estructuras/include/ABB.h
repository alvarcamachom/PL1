#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"
#include <iostream>
#include "Concesionario.h"
#include "Vehiculo.h"


class ABB
{
    public:
        ABB(int);
        ABB(NodoABB *r);
        ABB(Concesionario c, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        void verInOrden();
        void insertar(Concesionario c);
        void insertar(Vehiculo);
        void insertarVehiculo(Vehiculo, NodoABB*);
        virtual ~ABB();

    protected:

    private:
        NodoABB *raiz;
        void verInOrden(NodoABB *arb);
        void insertar(Concesionario c, NodoABB *nodo);

};

#endif // ABB_H
