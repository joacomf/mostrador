#ifndef NOTIFICACIONDEACKMESALISTA_H
#define NOTIFICACIONDEACKMESALISTA_H

#include "Notificacion.hpp"

class NotificacionDeAckMesaLista : public Notificacion {
    public:
        NotificacionDeAckMesaLista(string contenido, string idCliente);
        virtual void procesar();
};

#endif