#include "Editable.hpp"

Editable::Editable(char id){
    this->id = id;
    this->valor = "";
}

void Editable::agregarDigito(char digito){
    if(this->valor.length() < 3){
        this->valor += digito;
    }
}

void Editable::quitarUnDigito(){
    this->valor = this->valor.substr(0, this->valor.length() - 1);
}

void Editable::reiniciar(){
    this->valor = "";
}

char Editable::obtenerId(){
    return this->id;
}

string Editable::obtenerValor(){
    return this->valor;
}