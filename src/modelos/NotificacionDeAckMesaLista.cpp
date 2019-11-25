#include "NotificacionDeAckMesaLista.hpp"

NotificacionDeAckMesaLista::NotificacionDeAckMesaLista(string idCliente, Mensajero* mensajero)
    :Notificacion(idCliente, mensajero){
        this->contenido += "REC. MJE";
    }

void NotificacionDeAckMesaLista::procesar(Editable* cursor, Editable* cliente, Editable* tiempo){}