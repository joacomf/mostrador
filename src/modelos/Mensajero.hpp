#ifndef MENSAJERO_H
#define MENSAJERO_H

#include <string>
#include <map>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include "BandejaDeNotificaciones.hpp"
#include "Notificacion.hpp"
#include "NotificacionDeSolicitudDeEspera.hpp"
#include "NotificacionDeAckMesaLista.hpp"
#include "NotificacionDeSolicitudDeMozo.hpp"

using namespace std;

class Mensajero {
    public:
        Mensajero(BandejaDeNotificaciones* bandeja);
        void notificarEspera(string idCliente, int minutos);
        void notificarMesaLista(string idCliente);
        void notificarRecepcionSolicitudMozo(string idCliente);
        bool estaRegistrado(string idCliente);
    private:
        BandejaDeNotificaciones* bandeja;
        HTTPClient cliente;
        AsyncWebServer* servidor;
        std::map<string, string> clientesRegistrados;

        void iniciarAccessPoint();
        void iniciarServidor();
        void registrarCliente(string idCliente, string direccionIp);
};


#endif