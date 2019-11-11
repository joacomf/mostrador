#include "BandejaDeNotificaciones.hpp"

BandejaDeNotificaciones::BandejaDeNotificaciones(){
    this->notificacionActiva = 0;
}

void BandejaDeNotificaciones::agregarNotificacion(string notificacion){
    this->notificaciones.push_back(notificacion);
    this->notificacionSiguiente();
}

void BandejaDeNotificaciones::notificacionSiguiente(){
    if(this->notificacionActiva < this->notificaciones.size() - 1){
        this->notificacionActiva++;
    }
}

void BandejaDeNotificaciones::notificacionAnterior(){
    if(this->notificacionActiva > 0){
        this->notificacionActiva--;
    }
}

string BandejaDeNotificaciones::mostrarNotificacionActiva(){
    if(!this->notificaciones.empty()){
        return this->notificaciones.at(this->notificacionActiva);
    } else {
        return "";
    }
}