#ifndef GESTOR_H
#define GESTOR_H
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"

using namespace std;

class Gestor
{
    public:
        Gestor();
        virtual ~Gestor();
        static string generarBastidorRand();
        static string modeloRand();
        static string colorRand();
        static int generarNC();
        static int generarNV();
        static int generarNS();
        static int generarNP();
        void crearVehiculo(int nv);
        void mostrarVehiculosFabrica();
        void borrarVehiculosFabrica();
        Cola vehiculosFabrica;

    protected:

    private:
};

#endif // GESTOR_H
