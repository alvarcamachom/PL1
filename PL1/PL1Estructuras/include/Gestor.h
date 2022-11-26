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
                ZonaReparto zonas [4];
                int np = 7; //esto deberia estar en el main, y creo que en los .h no se da valor, solo se define
                int nc = 5;
                ZonaReparto zona; //esto para que?
};

#endif // GESTOR_H
