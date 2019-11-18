#ifndef NOTIFICACIONDEMOZO_H
#define NOTIFICACIONDEMOZO_H

#include "Notificacion.hpp"

class NotificacionDeSolicitudDeMozo : public Notificacion {
    public:
        NotificacionDeSolicitudDeMozo(string contenido, int idCliente);
        virtual void procesar();
};

#endif