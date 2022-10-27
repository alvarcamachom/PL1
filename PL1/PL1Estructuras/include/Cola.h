#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include <string>
#include "Vehiculo.h"

class Cola
{
    public:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
    public:
        Cola();
        ~Cola();
        void encolar(Vehiculo v);
        Vehiculo inicio();
        Vehiculo fin();
        int get_longitud();
        Vehiculo desencolar();
        bool es_vacia();
        void mostrarCola();
};

#endif // COLAS_H
