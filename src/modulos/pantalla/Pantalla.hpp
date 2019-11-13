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

        void establecerCliente(string cliente);
        void establecerTiempo(string tiempo);
        void establecerNotificacion(string notificacion);
        void establecerCursor(char cursor);
        void reiniciarCambios();
    private:
        void imprimirMarco();
        void imprimirCliente();
        void imprimirTiempo();
        void imprimirNotificacion();
        void posicionarCursor();

        string cliente = "";
        string tiempo = "";
        string notificacion = "";
        bool hayCambios = true;
        char cursor;

        const short POSICION_INICIAL_CLIENTE = 0;
        const short POSICION_INICIAL_TIEMPO = 9;

        const short POSICION_CURSOR_CLIENTE = 4;
        const short POSICION_CURSOR_TIEMPO = 11;

        const short PRIMER_FILA = 0;
        const short SEGUNDA_FILA = 1;

        const char* CLIENTE_LABEL = "Cli:";
        const char* TIEMPO_LABEL = "T:";
};


#endif