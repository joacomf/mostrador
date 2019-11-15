#ifndef MENSAJERO_H
#define MENSAJERO_H

#include <string>
#include <map>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include "BandejaDeNotificaciones.hpp"

using namespace std;

class Mensajero {
    public:
        Mensajero(BandejaDeNotificaciones* bandeja);
        void notificarEspera(int idCliente, int minutos);
        void notificarMesaLista(int idCliente);
        void notificarRecepcionSolicitudMozo(int idCliente);
    private:
        BandejaDeNotificaciones* bandeja;
        HTTPClient* cliente;
        AsyncWebServer* servidor;
        std::map<int, string> clientesRegistrados;

        void iniciarAccessPoint();
        void iniciarServidor();
        void registrarCliente(string idCliente, string direccionIp);
};


#endif