#ifndef NOTIFICACIONDESOLICITUDESPERA_H
#define NOTIFICACIONDESOLICITUDESPERA_H

#include "Notificacion.hpp"

class NotificacionDeSolicitudDeEspera : public Notificacion {
    public:
        NotificacionDeSolicitudDeEspera(string idCliente, Mensajero* mensajero);
        virtual void procesar(Editable* cursor, Editable* cliente, Editable* tiempo);
};

#endif