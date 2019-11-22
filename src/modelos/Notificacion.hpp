#ifndef NOTIFICACION_H
#define NOTIFICACION_H

class Mensajero;

#include "Editable.hpp"
#include <string>
using namespace std;

class Notificacion {
    public:
        Notificacion(string contenido, string idCliente, Mensajero* mensajero);
        string obtenerContenido();
        string obtenerIdCliente();
        virtual void procesar(Editable* cursor, Editable* cliente, Editable* tiempo) = 0;
        virtual ~Notificacion();
    private:
        string contenido;
        string idCliente;
    protected:
        Mensajero* mensajero;
};

#endif