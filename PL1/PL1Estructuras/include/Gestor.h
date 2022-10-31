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

    protected:

    private:
};

#endif // GESTOR_H
