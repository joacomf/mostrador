#include "Notificador.hpp"

Notificador::Notificador(){
    this->notificacionActiva = 0;
}

void Notificador::agregarNotificacion(string notificacion){
    this->notificaciones.push_back(notificacion);
    this->incrementarNotificacionActiva();
}

void Notificador::incrementarNotificacionActiva(){
    if(this->notificacionActiva < this->notificaciones.size() - 1){
        this->notificacionActiva++;
    }
}

void Notificador::disminuirNotificacionActiva(){
    if(this->notificacionActiva > 0){
        this->notificacionActiva--;
    }
}

string Notificador::mostrarNotificacionActiva(){
    if(!this->notificaciones.empty()){
        return this->notificaciones.at(this->notificacionActiva);
    } else {
        return "";
    }
}