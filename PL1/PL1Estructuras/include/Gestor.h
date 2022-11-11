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
        static int generarNC();
        int generarNV();
        int generarNS();
        static int generarNP();
        void crearVehiculo(int nv);
        void mostrarVehiculosFabrica();
        void borrarVehiculosFabrica();
        void vehiculosAZona(int ns, ZonaReparto zona);


        Cola vehiculosFabrica;


    protected:

    private:
};

#endif // GESTOR_H
