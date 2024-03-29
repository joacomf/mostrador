#include "Pantalla.hpp"

LiquidCrystal lcd(22, 23, 5, 18, 19, 21);

Pantalla::Pantalla() {
    lcd.begin(16, 2);
    lcd.cursor();
}

void Pantalla::mostrar() {
    if(this->hayCambios){
        this->imprimirMarco();
        this->imprimirCliente();
        this->imprimirTiempo();
        this->imprimirNotificacion();
        this->imprimirCantidadDeNotificaciones();
        this->posicionarCursor();
        this->reiniciarCambios();
        delay(100);
    }
}

void Pantalla::reiniciarCambios(){
    this->hayCambios = false;
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

void Pantalla::imprimirCantidadDeNotificaciones(){
    if(cantidadDeNotificaciones > 0){
        lcd.setCursor(14, this->PRIMER_FILA);
        lcd.print(this->cantidadDeNotificaciones);
    }
}

void Pantalla::imprimirNotificacion(){
    lcd.home();
    lcd.print(this->notificacion.c_str());
}

void Pantalla::posicionarCursor(){
    if (this->cursor == 'C'){
        lcd.setCursor(this->POSICION_CURSOR_CLIENTE + this->cliente.length(), this->SEGUNDA_FILA);
    }else{
        lcd.setCursor(this->POSICION_CURSOR_TIEMPO + this->tiempo.length(), this->SEGUNDA_FILA);
    }
}

void Pantalla::establecerCliente(string cliente){
    this->hayCambios = this->hayCambios || (cliente != this->cliente);
    this->cliente = cliente;
}
void Pantalla::establecerTiempo(string tiempo){
    this->hayCambios = this->hayCambios || (tiempo != this->tiempo);
    this->tiempo = tiempo;
}
void Pantalla::establecerNotificacion(string notificacion){
    this->hayCambios = this->hayCambios || (notificacion != this->notificacion);
    this->notificacion = notificacion;
    
}

void Pantalla::establecerCantidadDeNotificaciones(int cantidadDeNotificaciones){
    this->hayCambios = this->hayCambios || (cantidadDeNotificaciones != this->cantidadDeNotificaciones);
    this->cantidadDeNotificaciones = cantidadDeNotificaciones;
}

void Pantalla::establecerCursor(char cursor){
    this->hayCambios = this->hayCambios || (cursor != this->cursor);
    this->cursor = cursor;
}