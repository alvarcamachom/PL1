#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Vehiculo.h"
#include <cstddef>

class NodoCola
{
    friend class Cola;
    private:
        NodoCola *siguiente;
        Vehiculo v;
    public:
        NodoCola();
        NodoCola(Vehiculo v, NodoCola*sig = NULL);
        ~NodoCola();
};

#endif // NODOCOLA_H
