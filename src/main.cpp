#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Cliente.hpp"
#include "modelos/Tiempo.hpp"
#include "modelos/BandejaDeNotificaciones.hpp"

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Cliente* cliente;
Tiempo* tiempo;
BandejaDeNotificaciones* bandejaDeNotificaciones;

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
}