#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Mesa.hpp"
#include "modelos/Tiempo.hpp"
#include "modelos/Notificador.hpp"

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Mesa* mesa;
Tiempo* tiempo;
Notificador* notificador;

void setup() {
    Serial.begin(115200);
    teclado = new Teclado();
    pantalla = new Pantalla();
    mesa = new Mesa();
    tiempo = new Tiempo();
    notificador = new Notificador();
    cursor = mesa;
    notificador->agregarNotificacion("Noti1");
    notificador->agregarNotificacion("Noti2");
}

void decidirQueHacer(char teclaPresionada){
  switch (teclaPresionada){
    case 'A':
        notificador->disminuirNotificacionActiva();
        break;
    case 'B':
        notificador->incrementarNotificacionActiva();
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
    pantalla->establecerNotificacion(notificador->mostrarNotificacionActiva());
    pantalla->establecerCursor(cursor->obtenerId());
    pantalla->mostrar();
}

void loop() {
    char teclaPresionada = teclado->leer();
    decidirQueHacer(teclaPresionada);
    actualizarPantalla();
}