#ifndef BANDEJADENOTIFICACIONES_H
#define BANDEJADENOTIFICACIONES_H

#include <string>
#include <vector>
#include "Notificacion.hpp"
#include "ControladorDeAlertas.hpp"

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
        int cantidadDeNotificaciones();
    private:
        vector<Notificacion*> notificaciones;
        ControladorDeAlertas* controladorDeAlertas;
        int notificacionActiva;
        
};


#endif