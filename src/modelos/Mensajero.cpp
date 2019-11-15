#include "Mensajero.hpp"

Mensajero::Mensajero(BandejaDeNotificaciones* bandeja){
    this->bandeja = bandeja;
    this->servidor = new AsyncWebServer(80);
    this->iniciarAccessPoint();
    this->iniciarServidor();
}

void Mensajero::iniciarAccessPoint(){
    IPAddress localIp(192, 168, 1, 2);
    IPAddress gateway(192, 168, 1, 1);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.softAP("ESP32", "12345678");
    WiFi.softAPConfig(localIp, gateway, subnet);
    delay(100);
}

void Mensajero::iniciarServidor(){
    this->servidor->on("/ping", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "pong");
    });

    this->servidor->on("/pedir_mozo", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* param = request->getParam(0);
        if(param != NULL && param->name() == "cliente"){
            string notificacion = param->value().c_str();
            notificacion += " MOZO";
            this->bandeja->agregarNotificacion(notificacion);
            request->send(200, "text/plain", "Mozo Solicitado");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->on("/preguntar_espera", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* param = request->getParam(0);
        if(param != NULL && param->name() == "cliente"){
            string notificacion = param->value().c_str();
            notificacion += " CONS. ESPERA";
            this->bandeja->agregarNotificacion(notificacion);
            request->send(200, "text/plain", "Espera consultada");
        }
        request->send(400, "text/plain", "Error de parametros");
    });
    this->servidor->begin();
}