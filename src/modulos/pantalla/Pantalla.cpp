#include "Pantalla.hpp"

LiquidCrystal lcd(22, 23, 5, 18, 19, 21);

Pantalla::Pantalla() {
    lcd.begin(16, 2);
    lcd.cursor();
}

void Pantalla::mostrar() {
    this->imprimirMarco();
    this->imprimirCliente();
    this->imprimirTiempo();
    this->imprimirNotificacion();
    this->posicionarCursor();
    delay(100);
}

void Pantalla::imprimirMarco(){
    lcd.clear();
    lcd.setCursor(this->POSICION_INICIAL_CLIENTE, this->SEGUNDA_FILA);
    lcd.print(this->CLIENTE_LABEL);
    lcd.setCursor(this->POSICION_INICIAL_TIEMPO, this->SEGUNDA_FILA);
    lcd.print(this->TIEMPO_LABEL);
}

void Pantalla::imprimirCliente(){
    lcd.setCursor(this->POSICION_CURSOR_CLIENTE, this->SEGUNDA_FILA);
    lcd.print(this->cliente.c_str());
}


void Pantalla::imprimirTiempo(){
    lcd.setCursor(this->POSICION_CURSOR_TIEMPO, this->SEGUNDA_FILA);
    lcd.print(this->tiempo.c_str());
}

void Pantalla::imprimirNotificacion(){
    lcd.home();
    string contenidoNotificacion = "";
    if(this->notificacion != NULL){
        contenidoNotificacion = this->notificacion->obtenerContenido();
    }
    lcd.print(contenidoNotificacion.c_str());
}

void Pantalla::posicionarCursor(){
    if (this->cursor == 'C'){
        lcd.setCursor(this->POSICION_CURSOR_CLIENTE + this->cliente.length(), this->SEGUNDA_FILA);
    }else{
        lcd.setCursor(this->POSICION_CURSOR_TIEMPO + this->tiempo.length(), this->SEGUNDA_FILA);
    }
}

void Pantalla::establecerCliente(string cliente){
    this->cliente = cliente;
}
void Pantalla::establecerTiempo(string tiempo){
    this->tiempo = tiempo;
}
void Pantalla::establecerNotificacion(Notificacion* notificacion){
    this->notificacion = notificacion;
}
void Pantalla::establecerCursor(char cursor){
    this->cursor = cursor;
}