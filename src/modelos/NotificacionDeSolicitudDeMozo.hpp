#ifndef NOTIFICACIONDEMOZO_H
#define NOTIFICACIONDEMOZO_H

#include "Notificacion.hpp"

class NotificacionDeSolicitudDeMozo : public Notificacion {
    public:
        NotificacionDeSolicitudDeMozo(string contenido, string idCliente);
        virtual void procesar();
};

#endif