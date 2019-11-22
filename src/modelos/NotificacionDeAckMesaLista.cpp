#include "NotificacionDeAckMesaLista.hpp"

NotificacionDeAckMesaLista::NotificacionDeAckMesaLista(string contenido, string idCliente, Mensajero* mensajero)
    :Notificacion(contenido, idCliente, mensajero){}

void NotificacionDeAckMesaLista::procesar(Editable* cursor, Editable* cliente, Editable* tiempo){}