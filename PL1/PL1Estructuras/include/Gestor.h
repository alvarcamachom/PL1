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
        void vehiculosAZona(Cola peds);
        void mostrarZonas();
        void finSimulacion(int ns);
        void finSimulacionPedidos();
        void pruebaLista();
        void generarNVVehiculos(int nv);
        void generarPedidos(int nc);
        void generarPedidosCustom(int nc);
        void verPedidos();
        void borrarPedidos();
        Cola buscaPedidos(int ns);
        void insertAutomovilABB(string, string, int, string);


    protected:

    private:

        ZonaReparto zonas [4];
        Cola vehiculosFabrica;
        Cola colaAux;
        Lista listaPedidos;

        ZonaReparto zona; //esto para que? --no se
};

#endif // GESTOR_H
