#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Mesa.hpp"
#include "modelos/Tiempo.hpp"

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Mesa* mesa;
Tiempo* tiempo;

void setup() {
  Serial.begin(115200);
  teclado = new Teclado();
  pantalla = new Pantalla();
  mesa = new Mesa();
  tiempo = new Tiempo();
  cursor = mesa;
}

void decidirQueHacer(char teclaPresionada){
  switch (teclaPresionada){
    case 'A':
        break;
    case 'B':
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


void loop() {
  char teclaPresionada = teclado->leer();
  decidirQueHacer(teclaPresionada);
  pantalla->establecerMesa(mesa->obtenerValor());
  pantalla->establecerTiempo(tiempo->obtenerValor());
  pantalla->establecerNotificacion("");
  pantalla->establecerCursor(cursor->obtenerId());
  pantalla->mostrar();
}