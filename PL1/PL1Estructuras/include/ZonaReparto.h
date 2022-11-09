#ifndef ZONAREPARTO_H
#define ZONAREPARTO_H
#include "Cola.h"
using namespace std;

class ZonaReparto
{
    public:
        ZonaReparto();
        ZonaReparto(string);
        virtual ~ZonaReparto();
        string getNombre();
        Cola cola_zona; //debería ser private(?

    protected:

    private:
        string nombre;
};

#endif // ZONAREPARTO_H
