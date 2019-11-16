#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>
using namespace std;

class Notificacion {
    public:
        Notificacion(string contenido);
        string obtenerContenido();
        virtual void procesar() = 0;
    private:
        string contenido;
};

#endif