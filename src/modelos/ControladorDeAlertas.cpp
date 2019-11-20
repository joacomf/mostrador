#include "ControladorDeAlertas.hpp"

ControladorDeAlertas::ControladorDeAlertas(){
    ledcSetup(CANAL_PWM, FRECUENCIA_BUZZER_OFF, RESOLUCION_PWM);
}

void ControladorDeAlertas::comunicarNuevaNotificacion(){
    ledcAttachPin(PIN_BUZZER, FRECUENCIA_BUZZER_OFF);
    ledcWriteTone(0, FRECUENCIA_BUZZER_ON);
    delay(100);
    ledcWriteTone(0, FRECUENCIA_BUZZER_OFF);
    ledcDetachPin(PIN_BUZZER);
}
