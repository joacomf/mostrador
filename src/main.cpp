#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"

Teclado* teclado;
Pantalla* pantalla;

string valorActual;

void setup() {
  teclado = new Teclado();
  pantalla = new Pantalla();
}

void manejarInputs(char teclaPresionada){
  if (teclaPresionada != 'N'){
    valorActual += teclaPresionada;
  }
}

void loop() {
  char teclaPresionada = teclado->leer();
  manejarInputs(teclaPresionada);
  pantalla->establecerMesa(valorActual);
  pantalla->establecerTiempo("15");
  pantalla->establecerNotificacion("");
  pantalla->mostrar();
}