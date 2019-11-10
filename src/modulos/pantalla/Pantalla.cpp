#include "Pantalla.hpp"

LiquidCrystal lcd(22, 23, 5, 18, 19, 21);

Pantalla::Pantalla() {
    lcd.begin(16, 2);
    lcd.cursor();
}

void Pantalla::mostrar() {
    this->imprimirMarco();
    this->imprimirMesa();
    this->imprimirTiempo();
    this->imprimirNotificacion();
    this->posicionarCursor();
    delay(100);
}

void Pantalla::imprimirMarco(){
    lcd.clear();
    lcd.setCursor(this->POSICION_INICIAL_MESA, this->SEGUNDA_FILA);
    lcd.print(this->MESA_LABEL);
    lcd.setCursor(this->POSICION_INICIAL_TIEMPO, this->SEGUNDA_FILA);
    lcd.print(this->TIEMPO_LABEL);
}

void Pantalla::imprimirMesa(){
    lcd.setCursor(this->POSICION_CURSOR_MESA, this->SEGUNDA_FILA);
    lcd.print(this->mesa.c_str());
}


void Pantalla::imprimirTiempo(){
    lcd.setCursor(this->POSICION_CURSOR_TIEMPO, this->SEGUNDA_FILA);
    lcd.print(this->tiempo.c_str());
}

void Pantalla::imprimirNotificacion(){
    // Implementar
}

void Pantalla::posicionarCursor(){
    if (this->cursor == 'M'){
        lcd.setCursor(this->POSICION_CURSOR_MESA + this->mesa.length(), this->SEGUNDA_FILA);
    }else{
        lcd.setCursor(this->POSICION_CURSOR_TIEMPO + this->tiempo.length(), this->SEGUNDA_FILA);
    }
}

void Pantalla::establecerMesa(string mesa){
    this->mesa = mesa;
}
void Pantalla::establecerTiempo(string tiempo){
    this->tiempo = tiempo;
}
void Pantalla::establecerNotificacion(string notificacion){
    this->notificacion = notificacion;
}
void Pantalla::establecerCursor(char cursor){
    this->cursor = cursor;
}