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

void Mensajero::registrarCliente(string idCliente, string direccionIp){
    this->clientesRegistrados[int(idCliente.c_str())] = direccionIp;
    Serial.print("Registrado: ");
    Serial.println(this->clientesRegistrados[int(idCliente.c_str())].c_str());
}

void Mensajero::notificarEspera(int idCliente, int minutos){
    string ruta = this->clientesRegistrados[idCliente];
    ruta += "/notificar_espera?minutos=" + minutos;
    this->cliente->begin(ruta.c_str());
    int codigoRespuesta = this->cliente->GET();
    this->cliente->end();
}

void Mensajero::notificarMesaLista(int idCliente){
    string ruta = this->clientesRegistrados[idCliente];
    ruta += "/notificar_mesa_lista";
    this->cliente->begin(ruta.c_str());
    int codigoRespuesta = this->cliente->GET();
    this->cliente->end();
}

void Mensajero::notificarRecepcionSolicitudMozo(int idCliente){
    string ruta = this->clientesRegistrados[idCliente];
    ruta += "/notificar_recepcion_solicitud_mozo";
    this->cliente->begin(ruta.c_str());
    int codigoRespuesta = this->cliente->GET();
    this->cliente->end();
}

void Mensajero::iniciarServidor(){
    this->servidor->on("/ping", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "pong");
    });

    this->servidor->on("/pedir_mozo", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* cliente = request->getParam(0);
        if(cliente != NULL && cliente->name() == "cliente"){
            string idCliente = cliente->value().c_str();
            string notificacion = idCliente;
            notificacion += " MOZO";
            this->bandeja->agregarNotificacion(new NotificacionDeSolicitudDeMozo(notificacion, int(idCliente.c_str())));
            request->send(200, "text/plain", "Mozo Solicitado");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->on("/preguntar_espera", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* cliente = request->getParam(0);
        if(cliente != NULL && cliente->name() == "cliente"){
            string idCliente = cliente->value().c_str();
            string notificacion = idCliente;
            notificacion += " CONS. ESPERA";
            this->bandeja->agregarNotificacion(new NotificacionDeSolicitudDeEspera(notificacion, int(idCliente.c_str())));
            request->send(200, "text/plain", "Espera consultada");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->on("/confirmar_recepcion_mesa_lista", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* cliente = request->getParam(0);
        if(cliente != NULL && cliente->name() == "cliente"){
            string idCliente = cliente->value().c_str();
            string notificacion = idCliente.c_str();
            notificacion += " REC. MENSAJE";
            this->bandeja->agregarNotificacion(new NotificacionDeAckMesaLista(notificacion, int(idCliente.c_str())));
            request->send(200, "text/plain", "Confirmacion exitosa");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->on("/registrarse", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* cliente = request->getParam(0);
        AsyncWebParameter* ipCliente = request->getParam(1);
        string idCliente = cliente->value().c_str();
        if(cliente != NULL && ipCliente != NULL){
            this->registrarCliente(idCliente, ipCliente->value().c_str());
            request->send(200, "text/plain", "Registro exitoso");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->begin();
}