#ifndef BANDEJADENOTIFICACIONES_H
#define BANDEJADENOTIFICACIONES_H

#include <string>
#include <vector>
using namespace std;

class BandejaDeNotificaciones {
    public:
        BandejaDeNotificaciones();
        void agregarNotificacion(string notificacion);
        string mostrarNotificacionActiva();
        void notificacionSiguiente();
        void notificacionAnterior();
    private:
        vector<string> notificaciones;
        int notificacionActiva;
        
};


#endif