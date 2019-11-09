#include "Pantalla.hpp"

LiquidCrystal lcd(22, 23, 5, 18, 19, 21);

Pantalla::Pantalla() {
    lcd.begin(16, 2);
    lcd.cursor();
    lcd.blink();
}

void Pantalla::mostrar() {
    this->imprimirMarco();
    this->imprimirMesa();
    this->imprimirTiempo();
    this->imprimirNotificacion();
    this->posicionarCursor();
    delay(200);
}

void Pantalla::imprimirMarco(){
    lcd.setCursor(0, 1);
    lcd.print("Mesa:");
    lcd.setCursor(9, 1);
    lcd.print("T:");
}

void Pantalla::imprimirMesa(){
    lcd.setCursor(5, 1);
    lcd.print(this->mesa.c_str());
}


void Pantalla::imprimirTiempo(){
    lcd.setCursor(11, 1);
    lcd.print(this->tiempo.c_str());
}

void Pantalla::imprimirNotificacion(){
    // Implementar
}

void Pantalla::posicionarCursor(){
    if (this->cursor == 'M'){
        lcd.setCursor(5, 1);
    }else{
        lcd.setCursor(11, 1);
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