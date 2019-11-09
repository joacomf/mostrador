#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"

Teclado* teclado;
Pantalla* pantalla;

string mesa;
string tiempo;
char cursor = 'M';

void setup() {
  Serial.begin(115200);
  teclado = new Teclado();
  pantalla = new Pantalla();
}

void manejarNumero(char teclaPresionada){
  if(cursor == 'M'){
    mesa += teclaPresionada;
  } else {
    tiempo += teclaPresionada;
  }
}

void decidirQueHacer(char teclaPresionada){
  switch (teclaPresionada){
    case 'A':
        break;
    case 'B':
        break;
    case 'C':
        cursor = 'M';
        break;
    case 'D':
       cursor = 'T';
       break;
    case '*':
        break;
    case '#':
        break;
    case 'N':
        //Nada
        break;
    default:
        manejarNumero(teclaPresionada);
       break;
  }
}


void loop() {
  char teclaPresionada = teclado->leer();
  decidirQueHacer(teclaPresionada);
  pantalla->establecerMesa(mesa);
  pantalla->establecerTiempo(tiempo);
  pantalla->establecerNotificacion("");
  pantalla->establecerCursor(cursor);
  pantalla->mostrar();
}