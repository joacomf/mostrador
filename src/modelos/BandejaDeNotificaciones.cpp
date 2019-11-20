#include "BandejaDeNotificaciones.hpp"

BandejaDeNotificaciones::BandejaDeNotificaciones(){
    this->notificacionActiva = 0;
    this->controladorDeAlertas = new ControladorDeAlertas();
}

void BandejaDeNotificaciones::agregarNotificacion(Notificacion* notificacion){
    this->notificaciones.push_back(notificacion);
    this->controladorDeAlertas->comunicarNuevaNotificacion();
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

Notificacion* BandejaDeNotificaciones::mostrarNotificacionActiva(){
    if(!this->notificaciones.empty()){
        return this->notificaciones.at(this->notificacionActiva);
    } else {
        return NULL;
    }
}

string BandejaDeNotificaciones::obtenerTextoDeLaNotificacionActiva(){
    string texto = "";

    if(!this->notificaciones.empty()){
        texto = this->notificaciones.at(this->notificacionActiva)->obtenerContenido();
    }

    return texto;
}

void BandejaDeNotificaciones::eliminarNotificacionActiva(){
    if(this->notificaciones.size() > 0){
        delete this->notificaciones[this->notificacionActiva];
        this->notificaciones.erase(this->notificaciones.begin() + this->notificacionActiva);
        this->notificacionActiva = 0;
    }
}

int BandejaDeNotificaciones::cantidadDeNotificaciones(){
    return this->notificaciones.size();
}