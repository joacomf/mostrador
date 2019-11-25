#include "Notificacion.hpp"

Notificacion::Notificacion(string idCliente, Mensajero* mensajero){
    this->contenido = idCliente + " ";
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