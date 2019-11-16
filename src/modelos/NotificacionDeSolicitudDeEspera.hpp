#ifndef NOTIFICACIONDESOLICITUDESPERA_H
#define NOTIFICACIONDESOLICITUDESPERA_H

#include "Notificacion.hpp"

class NotificacionDeSolicitudDeEspera : public Notificacion {
    public:
        NotificacionDeSolicitudDeEspera(string contenido);
        virtual void procesar();
};

#endif