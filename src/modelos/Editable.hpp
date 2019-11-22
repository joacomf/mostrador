#ifndef Editable_H
#define Editable_H

#include <string>
using namespace std;

class Editable {
    public:
        Editable(char id);
        void establecerValor(string valor);
        void agregarDigito(char digito);
        void quitarUnDigito();
        void reiniciar();
        string obtenerValor();
        char obtenerId();
    private:
        string valor;
        char id;
};


#endif