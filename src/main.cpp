#include <Arduino.h>
#include "modulos/teclado/Teclado.hpp"
#include "modulos/pantalla/Pantalla.hpp"
#include "modelos/Editable.hpp"
#include "modelos/Cliente.hpp"
#include "modelos/Tiempo.hpp"
#include "modelos/BandejaDeNotificaciones.hpp"
#include "modelos/Mensajero.hpp"
#include "modelos/Notificacion.hpp"

Teclado* teclado;
Pantalla* pantalla;

Editable* cursor;
Cliente* cliente;
Tiempo* tiempo;
BandejaDeNotificaciones* bandejaDeNotificaciones;
Mensajero* mensajero;

void setup() {
    Serial.begin(115200);
    teclado = new Teclado();
    pantalla = new Pantalla();
    cliente = new Cliente();
    tiempo = new Tiempo();
    bandejaDeNotificaciones = new BandejaDeNotificaciones();
    cursor = cliente;
    mensajero = new Mensajero(bandejaDeNotificaciones);
}

void decidirQueHacer(char teclaPresionada){
  switch (teclaPresionada){
    case 'A':
        bandejaDeNotificaciones->notificacionAnterior();
        break;
    case 'B':
        bandejaDeNotificaciones->notificacionSiguiente();
        break;
    case 'C':
        if(cursor == cliente){
            cursor = tiempo;
        } else {
            cursor = cliente;
        }
        break;
    case 'D':
        cursor->quitarUnDigito();
        break;
    case '*':
        {
            Notificacion* notificacionActiva = bandejaDeNotificaciones->mostrarNotificacionActiva();
            if(notificacionActiva != NULL){
                notificacionActiva->procesar(cursor, cliente, tiempo);
                bandejaDeNotificaciones->eliminarNotificacionActiva();
            }

        }
        break;
    case '#':
        if(tiempo->obtenerValor() == "" || tiempo->obtenerValor() == "0"){
            mensajero->notificarMesaLista(cliente->obtenerValor());
        } else {
            mensajero->notificarEspera(cliente->obtenerValor(), tiempo->obtenerValor());
        }
        cliente->establecerValor("");
        tiempo->establecerValor("");
        cursor = cliente;
        break;
    case 'N':
        //Nada
        break;
    default:
        cursor->agregarDigito(teclaPresionada);
        break;
  }
}

void actualizarPantalla(){
    pantalla->establecerCliente(cliente->obtenerValor());
    pantalla->establecerTiempo(tiempo->obtenerValor());
    pantalla->establecerNotificacion(bandejaDeNotificaciones->obtenerTextoDeLaNotificacionActiva());
    pantalla->establecerCantidadDeNotificaciones(bandejaDeNotificaciones->cantidadDeNotificaciones());
    pantalla->establecerCursor(cursor->obtenerId());
    pantalla->mostrar();
}

void loop() {
    char teclaPresionada = teclado->leer();
    decidirQueHacer(teclaPresionada);
    actualizarPantalla();
}