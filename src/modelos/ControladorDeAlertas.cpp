#include "ControladorDeAlertas.hpp"

ControladorDeAlertas::ControladorDeAlertas(){
    ledcSetup(CANAL_PWM, FRECUENCIA_BUZZER_OFF, RESOLUCION_PWM);
    ledcAttachPin(PIN_BUZZER, FRECUENCIA_BUZZER_OFF);
}

void ControladorDeAlertas::comunicarNuevaNotificacion(){
    ledcWriteTone(0, FRECUENCIA_BUZZER_ON);
    delay(100);
    ledcWriteTone(0, FRECUENCIA_BUZZER_OFF);
}
