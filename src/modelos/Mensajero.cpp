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
    this->clientesRegistrados[idCliente] = direccionIp;
    Serial.print("Registrado: ");
    Serial.println(this->clientesRegistrados[idCliente].c_str());
}

bool Mensajero::estaRegistrado(string idCliente){
    return this->clientesRegistrados.find(idCliente) != this->clientesRegistrados.end();
}

void Mensajero::notificarEspera(string idCliente, string minutos){
    if(this->estaRegistrado(idCliente)){
        Serial.print("Voy a mandar notificacion de espera");
        string ruta = "http://" + this->clientesRegistrados[idCliente];
        ruta += "/notificar_espera?minutos=" + minutos;
        Serial.print(ruta.c_str());
        this->cliente.begin(ruta.c_str());
        int codigoRespuesta = this->cliente.GET();
        this->cliente.end();
    }
}

void Mensajero::notificarMesaLista(string idCliente){
    if(this->estaRegistrado(idCliente)){
        Serial.print("Voy a mandar notificacion mesa lista");
        string ruta = "http://" + this->clientesRegistrados[idCliente];
        ruta += "/notificar_mesa_lista";
        Serial.print(ruta.c_str());
        this->cliente.begin(ruta.c_str());
        int codigoRespuesta = this->cliente.GET();
        this->cliente.end();
    }
}

void Mensajero::notificarRecepcionSolicitudMozo(string idCliente){
    if(this->estaRegistrado(idCliente)){
        string ruta = "http://" + this->clientesRegistrados[idCliente];
        ruta += "/notificar_recepcion_solicitud_mozo";
        this->cliente.begin(ruta.c_str());
        int codigoRespuesta = this->cliente.GET();
        this->cliente.end();
    }
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
            this->bandeja->agregarNotificacion(new NotificacionDeSolicitudDeMozo(notificacion, idCliente, this));
            request->send(200, "text/plain", "Mozo Solicitado");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->on("/preguntar_espera", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* cliente = request->getParam(0);
        if(cliente != NULL && cliente->name() == "cliente"){
            string idCliente = cliente->value().c_str();
            string notificacion = idCliente;
            notificacion += " CONS. ESP.";
            this->bandeja->agregarNotificacion(new NotificacionDeSolicitudDeEspera(notificacion, idCliente, this));
            request->send(200, "text/plain", "Espera consultada");
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    this->servidor->on("/confirmar_recepcion_mesa_lista", HTTP_GET, [=](AsyncWebServerRequest *request){
        AsyncWebParameter* cliente = request->getParam(0);
        if(cliente != NULL && cliente->name() == "cliente"){
            string idCliente = cliente->value().c_str();
            string notificacion = idCliente.c_str();
            notificacion += " REC. MJE";
            this->bandeja->agregarNotificacion(new NotificacionDeAckMesaLista(notificacion, idCliente, this));
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