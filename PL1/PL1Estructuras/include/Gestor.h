#ifndef GESTOR_H
#define GESTOR_H
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"

using namespace std;

class Gestor
{
    public:
        Gestor();
        virtual ~Gestor();
        void crearVehiculo(int nv);
        void mostrarVehiculosFabrica();
        void borrarVehiculosFabrica();
        void vehiculosAZona(int zona, int ns);
        void mostrarZonas();
        void finSimulacion(int ns);


        Cola vehiculosFabrica;

    protected:

    private:

                int vectoro[4]={1,2,3,4};
                ZonaReparto zonas [4];
                int np = 7;
                int nc = 5;
                ZonaReparto zona;
};

#endif // GESTOR_H
