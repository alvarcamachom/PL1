#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H
#include "ListaVehiculos.h"
using namespace std;


class Concesionario
{
    public:
        Concesionario(int num, int zon, ListaVehiculos vConc);
        Concesionario();
        int getNumero();
        int getZona();
        ListaVehiculos getVehiculos();
        string verConcesionario();
        virtual ~Concesionario();

    protected:

    private:
        int numero;
        int zona;
        ListaVehiculos vehiculosConcesionario;
};

#endif // CONCESIONARIO_H
