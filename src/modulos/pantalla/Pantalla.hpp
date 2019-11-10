#ifndef Pantalla_H
#define Pantalla_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#include <string>
using namespace std;

class Pantalla {
    public:
        Pantalla();
        void mostrar();

        void establecerMesa(string mesa);
        void establecerTiempo(string tiempo);
        void establecerNotificacion(string notificacion);
        void establecerCursor(char cursor);
    private:
        void imprimirMarco();
        void imprimirMesa();
        void imprimirTiempo();
        void imprimirNotificacion();
        void posicionarCursor();

        string mesa = "";
        string tiempo = "";
        string notificacion = "";
        char cursor;

        const short POSICION_INICIAL_MESA = 0;
        const short POSICION_INICIAL_TIEMPO = 9;

        const short POSICION_CURSOR_MESA = 5;
        const short POSICION_CURSOR_TIEMPO = 11;

        const short PRIMER_FILA = 0;
        const short SEGUNDA_FILA = 1;

        const char* MESA_LABEL = "Mesa:";
        const char* TIEMPO_LABEL = "T:";
};


#endif