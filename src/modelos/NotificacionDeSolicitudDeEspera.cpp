#include "NotificacionDeSolicitudDeEspera.hpp"

NotificacionDeSolicitudDeEspera::NotificacionDeSolicitudDeEspera(string contenido, string idCliente, Mensajero* mensajero)
    :Notificacion(contenido, idCliente, mensajero){}

void NotificacionDeSolicitudDeEspera::procesar(Editable* cursor, Editable* cliente, Editable* tiempo){
    cliente->establecerValor(this->obtenerIdCliente());
    //cursor = tiempo;
}