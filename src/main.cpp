#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Mesa.hpp"
#include "modelos/Tiempo.hpp"
#include "modelos/BandejaDeNotificaciones.hpp"

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Mesa* mesa;
Tiempo* tiempo;
BandejaDeNotificaciones* bandejaDeNotificaciones;

void setup() {
    Serial.begin(115200);
    teclado = new Teclado();
    pantalla = new Pantalla();
    mesa = new Mesa();
    tiempo = new Tiempo();
    bandejaDeNotificaciones = new BandejaDeNotificaciones();
    cursor = mesa;
    bandejaDeNotificaciones->agregarNotificacion("Mesa 1 OK");
    bandejaDeNotificaciones->agregarNotificacion("Mesa 2 cuenta");
    bandejaDeNotificaciones->agregarNotificacion("Mesa 8 consulta");
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
        cursor = mesa;
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
    pantalla->establecerMesa(mesa->obtenerValor());
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