#ifndef NOTIFICACIONDESOLICITUDESPERA_H
#define NOTIFICACIONDESOLICITUDESPERA_H

#include "Notificacion.hpp"

class NotificacionDeSolicitudDeEspera : public Notificacion {
    public:
        NotificacionDeSolicitudDeEspera(string contenido, int idCliente);
        virtual void procesar();
};

#endif