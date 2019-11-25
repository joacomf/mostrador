#include "NotificacionDeSolicitudDeEspera.hpp"

NotificacionDeSolicitudDeEspera::NotificacionDeSolicitudDeEspera(string idCliente, Mensajero* mensajero)
    :Notificacion(idCliente, mensajero){
        this->contenido += "CONS. ESP.";
    }

void NotificacionDeSolicitudDeEspera::procesar(Editable* cursor, Editable* cliente, Editable* tiempo){
    cliente->establecerValor(this->obtenerIdCliente());
    //cursor = tiempo;
}