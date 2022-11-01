#ifndef GESTOR_H
#define GESTOR_H
#include "Vehiculo.h"

using namespace std;

class Gestor
{
    public:
        Gestor();
        virtual ~Gestor();
        static string generarBastidorRand();
        static string modeloRand();
        static string colorRand();
        static string concesionarioRand();
        static int generarNC();
        static int generarNV();
        static int generarNS();
        static int generarNP();

    protected:

    private:
};

#endif // GESTOR_H
