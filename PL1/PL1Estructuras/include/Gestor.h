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
        void pruebaLista();


    protected:

    private:

        ZonaReparto zonas [4];
        Cola vehiculosFabrica;
        ZonaReparto zona; //esto para que?
};

#endif // GESTOR_H
