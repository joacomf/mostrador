#include "Notificacion.hpp"

Notificacion::Notificacion(string contenido, int idCliente){
    this->contenido = contenido;
    this->idCliente = idCliente;
}

string Notificacion::obtenerContenido(){
    return this->contenido;
}

int Notificacion::obtenerIdCliente(){
    return this->idCliente;
}