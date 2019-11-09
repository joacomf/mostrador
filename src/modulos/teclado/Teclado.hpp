#ifndef TECLADO_H
#define TECLADO_H

#include <Arduino.h>
#include <string>
using namespace std;

#define FILAS 4
#define COLUMNAS 4
#define TIEMPO_ENTRE_PULSACIONES 300

class Teclado {
    public:
        Teclado();
        char leer();
    
    private:
        const char teclas[FILAS][COLUMNAS] = {
            {'1','2','3','A'},
            {'4','5','6','B'},
            {'7','8','9','C'},
            {'*','0','#','D'}
        };
        const short pinsDeFila[FILAS] = {12, 14, 17, 16};
        const short pinsDeColumnas[COLUMNAS] = {4, 0, 2, 15};

        unsigned long temporizador = 0;
};

#endif