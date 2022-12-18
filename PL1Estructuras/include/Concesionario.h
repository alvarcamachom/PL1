#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H
#include "Lista.h"
using namespace std;


class Concesionario
{
    public:
        Concesionario(int num, int zon, Lista vConc);
        Concesionario();
        int getNumero();
        int getZona();
        Lista getVehiculos();
        string verConcesionario();
        virtual ~Concesionario();

    protected:

    private:
        int numero;
        int zona;
        Lista vehiculosConcesionario;
};

#endif // CONCESIONARIO_H
