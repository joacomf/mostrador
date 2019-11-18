#ifndef NOTIFICACIONDESOLICITUDESPERA_H
#define NOTIFICACIONDESOLICITUDESPERA_H

#include "Notificacion.hpp"

class NotificacionDeSolicitudDeEspera : public Notificacion {
    public:
        NotificacionDeSolicitudDeEspera(string contenido, string idCliente);
        virtual void procesar();
};

#endif