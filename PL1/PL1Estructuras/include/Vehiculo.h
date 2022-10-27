#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <list>
#include <cstdlib>
#include <time.h>


class Vehiculo
{
    public:
        //Constructores
        Vehiculo();
        Vehiculo(std::string m, std::string c, std::string b, int conc);
        virtual ~Vehiculo();
        std::string verVehiculo();
        void cargarVehiculo(std::string m, std::string c, std::string b, int conc);
        std::string devolverModelo();
        std::string devolverColor();
        std::string devolverBastidor();
        int devolverConcesionario();
        /*std::string color[6] = {"azul","amarillo","verde","rojo","morado","negro"};
        list<string> modelo  {"Zafira","Octavia","Golf","Astra","Insignia","Polo"};
        list<char> letras {"a","b","c","d","e","f"};*/


    protected:

    private:
        std::string modelo, color, bastidor;
        int concesionario;
};

#endif // VEHICULO_H
