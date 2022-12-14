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
        Vehiculo(string m, string c);
        virtual ~Vehiculo();

        //Setters
        string generarBastidorRand();
        string modeloRand();
        string colorRand();
        void set_concesionario(int);
        void setZona(int);

        //Getters
        string verVehiculo();
        string devolverModelo();
        string devolverColor();
        string devolverBastidor();
        int devolverConcesionario();
        int getZona();

        //Pedir
        string pedirModelo();
        string pedirColor();
        string pedirTipo();
        string pedirBastidor();
        int pedirConcesionario(int);


    protected:

    private:
        string modelo, color, bastidor;
        int concesionario;
        int zona;
};

#endif // VEHICULO_H
