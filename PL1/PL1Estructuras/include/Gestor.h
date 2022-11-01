#ifndef GESTOR_H
#define GESTOR_H
#include "vehiculo.h"



class Gestor
{
    public:
        Gestor();
        virtual ~Gestor();
        static std::string generarBastidorRand();
    protected:

    private:
};

#endif // GESTOR_H
