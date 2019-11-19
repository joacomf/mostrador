#include "Notificacion.hpp"

Notificacion::Notificacion(string contenido, string idCliente){
    this->contenido = contenido;
    this->idCliente = idCliente;
}

string Notificacion::obtenerContenido(){
    return this->contenido;
}

string Notificacion::obtenerIdCliente(){
    return this->idCliente;
}

Notificacion::~Notificacion(){}