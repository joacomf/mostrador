#include "Notificacion.hpp"

Notificacion::Notificacion(string contenido, string idCliente, Mensajero* mensajero){
    this->contenido = contenido;
    this->idCliente = idCliente;
    this->mensajero = mensajero;
}

string Notificacion::obtenerContenido(){
    return this->contenido;
}

string Notificacion::obtenerIdCliente(){
    return this->idCliente;
}

Notificacion::~Notificacion(){}