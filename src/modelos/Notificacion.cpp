#include "Notificacion.hpp"

Notificacion::Notificacion(string contenido){
    this->contenido = contenido;
}

string Notificacion::obtenerContenido(){
    return this->contenido;
}