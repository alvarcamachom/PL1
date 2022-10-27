#ifndef GESTOR_H
#define GESTOR_H
#include "vehiculo.h"


class Gestor
{
    public:
        Gestor();
        virtual ~Gestor();
        Vehiculo generarVehiculoRand();
    protected:

    private:
};

#endif // GESTOR_H
