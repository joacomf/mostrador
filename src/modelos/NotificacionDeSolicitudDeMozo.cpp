#include "NotificacionDeSolicitudDeMozo.hpp"

NotificacionDeSolicitudDeMozo::NotificacionDeSolicitudDeMozo(string contenido, string idCliente, Mensajero* mensajero)
    :Notificacion(contenido, idCliente, mensajero){}

void NotificacionDeSolicitudDeMozo::procesar(Editable* cursor, Editable* cliente, Editable* tiempo){
    this->mensajero->notificarRecepcionSolicitudMozo(this->obtenerIdCliente());
}