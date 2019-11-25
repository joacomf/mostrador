#include "NotificacionDeSolicitudDeMozo.hpp"
#include "Mensajero.hpp"

NotificacionDeSolicitudDeMozo::NotificacionDeSolicitudDeMozo(string idCliente, Mensajero* mensajero)
    :Notificacion(idCliente, mensajero){
        this->contenido += "MOZO";
    }

void NotificacionDeSolicitudDeMozo::procesar(Editable* cursor, Editable* cliente, Editable* tiempo){
    this->mensajero->notificarRecepcionSolicitudMozo(this->obtenerIdCliente());
}