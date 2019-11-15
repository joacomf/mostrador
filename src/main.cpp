#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Cliente.hpp"
#include "modelos/Tiempo.hpp"
#include "modelos/BandejaDeNotificaciones.hpp"
#include "modelos/Mensajero.hpp"
#include "modelos/Notificacion.hpp"

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Cliente* cliente;
Tiempo* tiempo;
BandejaDeNotificaciones* bandejaDeNotificaciones;
Mensajero* mensajero;

void setup() {
    Serial.begin(115200);
    teclado = new Teclado();
    pantalla = new Pantalla();
    cliente = new Cliente();
    tiempo = new Tiempo();
    bandejaDeNotificaciones = new BandejaDeNotificaciones();
    cursor = cliente;
    mensajero = new Mensajero(bandejaDeNotificaciones);
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
    pantalla->establecerNotificacion(bandejaDeNotificaciones->obtenerTextoDeLaNotificacionActiva());
    pantalla->establecerCursor(cursor->obtenerId());
    pantalla->mostrar();
}

void loop() {
    char teclaPresionada = teclado->leer();
    decidirQueHacer(teclaPresionada);
    actualizarPantalla();
}