#ifndef BANDEJADENOTIFICACIONES_H
#define BANDEJADENOTIFICACIONES_H

#include <string>
#include <vector>
#include "Notificacion.hpp"
using namespace std;

class BandejaDeNotificaciones {
    public:
        BandejaDeNotificaciones();
        void agregarNotificacion(Notificacion* notificacion);
        Notificacion* mostrarNotificacionActiva();
        void notificacionSiguiente();
        void notificacionAnterior();
        string obtenerTextoDeLaNotificacionActiva();
        void eliminarNotificacion(int posicion);
        void eliminarNotificacionActiva();
    private:
        vector<Notificacion*> notificaciones;
        int notificacionActiva;
        
};


#endif