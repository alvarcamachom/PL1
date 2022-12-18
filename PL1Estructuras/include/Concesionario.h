#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H
#include "Lista.h"
using namespace std;


class Concesionario
{
    public:
        Concesionario(int num, string zon, Lista vConc);
        Concesionario();
        int getNumero();
        string getZona();
        Lista getVehiculos();
        string verConcesionario();
        virtual ~Concesionario();

    protected:

    private:
        int numero;
        string zona;
        Lista vehiculosConcesionario;
};

#endif // CONCESIONARIO_H
