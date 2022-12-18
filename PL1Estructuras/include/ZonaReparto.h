#ifndef ZONAREPARTO_H
#define ZONAREPARTO_H
#include "Cola.h"
#include "Pila.h"
#include "Vehiculo.h"
using namespace std;

class ZonaReparto
{
public:
    ZonaReparto();
    ZonaReparto(string);
    virtual ~ZonaReparto();
    string getNombre();
    void setNombre(string);
    void verRegistro();
    void meterRegistro(Vehiculo);
    Vehiculo sacarRegistro();
    void verCamion1();
    void verCamion2();
    bool esCamion1Vacio();
    bool esCamion2Vacio();
    void meterCamion1(Vehiculo);
    void meterCamion2(Vehiculo);
    void sacarCamion1();
    void sacarCamion2();
    int profundidadCamion1();
    int profundidadCamion2();
    Vehiculo mostrarCamion1(); //Mostrar es devolver la cima
    Vehiculo mostrarCamion2(); //Mostrar es devolver la cima




protected:

private:
    string nombre;
    Cola vehiculosZona;
    Pila camion1;
    Pila camion2;

};

#endif // ZONAREPARTO_H
