#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Cliente.hpp"
#include "modelos/Tiempo.hpp"
#include "modelos/BandejaDeNotificaciones.hpp"
#include <HTTPClient.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Cliente* cliente;
Tiempo* tiempo;
BandejaDeNotificaciones* bandejaDeNotificaciones;
HTTPClient client;
AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);
    teclado = new Teclado();
    pantalla = new Pantalla();
    cliente = new Cliente();
    tiempo = new Tiempo();
    bandejaDeNotificaciones = new BandejaDeNotificaciones();
    cursor = cliente;
    bandejaDeNotificaciones->agregarNotificacion("1 REC. MENSAJE");
    bandejaDeNotificaciones->agregarNotificacion("2 MOZO");
    bandejaDeNotificaciones->agregarNotificacion("8 CONS. ESPERA");
    server.on("/ping", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "pong");
    });
    WiFi.softAP("ESP32", "12345678");
    Serial.print("IP:");
    Serial.println(WiFi.softAPIP());
    server.begin();
}

void decidirQueHacer(char teclaPresionada){
  switch (teclaPresionada){
    case 'A':
        bandejaDeNotificaciones->notificacionAnterior();
        break;
    case 'B':
        bandejaDeNotificaciones->notificacionSiguiente();
        break;
    case 'C':
        cursor = cliente;
        break;
    case 'D':
        cursor = tiempo;
        break;
    case '*':
        break;
    case '#':
        cursor->quitarUnDigito();
        break;
    case 'N':
        //Nada
        break;
    default:
        cursor->agregarDigito(teclaPresionada);
       break;
  }
}

void actualizarPantalla(){
    pantalla->establecerCliente(cliente->obtenerValor());
    pantalla->establecerTiempo(tiempo->obtenerValor());
    pantalla->establecerNotificacion(bandejaDeNotificaciones->mostrarNotificacionActiva());
    pantalla->establecerCursor(cursor->obtenerId());
    pantalla->mostrar();
}

void loop() {
    char teclaPresionada = teclado->leer();
    decidirQueHacer(teclaPresionada);
    actualizarPantalla();
    client.begin("http://192.168.4.2:5000/build");
    int responseCode = client.GET();
    Serial.print("Respuesta: ");
    Serial.print(responseCode);
    Serial.print(client.getString());
    delay(1000);
}