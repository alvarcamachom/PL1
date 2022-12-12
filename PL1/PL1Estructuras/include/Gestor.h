#ifndef GESTOR_H
#define GESTOR_H
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"
#include "Lista.h"
#include "Pedido.h"

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
        void generarNVVehiculos(int nv);
        void generarPedidos(int nc);
        void verPedidos();
        void borrarPedidos();
        void buscarListaPedidos();


    protected:

    private:

        ZonaReparto zonas [4];
        Cola vehiculosFabrica;
        Cola colaAux;
        Lista listaPedidos;

        ZonaReparto zona; //esto para que? --no se
};

#endif // GESTOR_H
