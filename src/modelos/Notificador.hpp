#ifndef NOTIFICADOR_H
#define NOTIFICADOR_H

#include <string>
#include <vector>
using namespace std;

class Notificador {
    public:
        Notificador();
        void agregarNotificacion(string notificacion);
        string mostrarNotificacionActiva();
        void incrementarNotificacionActiva();
        void disminuirNotificacionActiva();
    private:
        vector<string> notificaciones;
        int notificacionActiva;
        
};


#endif