#ifndef MENSAJERO_H
#define MENSAJERO_H

#include <string>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include "BandejaDeNotificaciones.hpp"

using namespace std;

class Mensajero {
    public:
        Mensajero(BandejaDeNotificaciones* bandeja);
    private:
        BandejaDeNotificaciones* bandeja;
        HTTPClient* cliente;
        AsyncWebServer* servidor;

        void iniciarAccessPoint();
        void iniciarServidor();
};


#endif