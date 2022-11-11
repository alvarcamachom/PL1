#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <list>
#include <cstdlib>
#include <time.h>

using namespace std;

class Vehiculo
{
    public:
        //Constructores
        Vehiculo();
        Vehiculo(string m, string c, string b, int con);
        virtual ~Vehiculo();
        string verVehiculo();
        string devolverModelo();
        string devolverColor();
        string devolverBastidor();
        int devolverConcesionario();

    protected:

    private:
        string modelo, color, bastidor;
        int concesionario;
};

#endif // VEHICULO_H
