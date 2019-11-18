#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>
using namespace std;

class Notificacion {
    public:
        Notificacion(string contenido, int idCliente);
        string obtenerContenido();
        int obtenerIdCliente();
        virtual void procesar() = 0;
    private:
        string contenido;
        int idCliente;
};

#endif