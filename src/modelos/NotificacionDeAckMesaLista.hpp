#ifndef NOTIFICACIONDEACKMESALISTA_H
#define NOTIFICACIONDEACKMESALISTA_H

#include "Notificacion.hpp"

class NotificacionDeAckMesaLista : public Notificacion {
    public:
        NotificacionDeAckMesaLista(string contenido);
        virtual void procesar();
};

#endif