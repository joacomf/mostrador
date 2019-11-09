#include "Teclado.hpp"

Teclado::Teclado() {
    for (size_t fila = 0; fila < FILAS; fila++){
        pinMode(this->pinsDeFila[fila], OUTPUT);
    }

    for (size_t columna = 0; columna < COLUMNAS; columna++){
        pinMode(this->pinsDeColumnas[columna], INPUT_PULLUP);
    }
}

char Teclado::leer() {
    char teclaPresionada = 'N';
    unsigned long tiempoActual = millis();

    if (tiempoActual > this->temporizador + TIEMPO_ENTRE_PULSACIONES){

        for (size_t fila = 0; fila < FILAS; fila++){
            digitalWrite(this->pinsDeFila[fila], LOW);

            for (size_t columna = 0; columna < COLUMNAS; columna++){
                if (digitalRead(this->pinsDeColumnas[columna]) == LOW) {
                    teclaPresionada = this->teclas[fila][columna];
                    this->temporizador = millis();
                }
            }

            digitalWrite(this->pinsDeFila[fila], HIGH);
        }
    }

    return teclaPresionada;
}