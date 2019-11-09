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
};


#endif