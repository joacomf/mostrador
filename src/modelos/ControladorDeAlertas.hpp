#ifndef CONTROLADORDEALERTAS_H
#define CONTROLADORDEALERTAS_H

#include <Arduino.h>

#define CANAL_PWM 0
#define RESOLUCION_PWM 8
#define PIN_BUZZER 25
#define FRECUENCIA_BUZZER_OFF 0
#define FRECUENCIA_BUZZER_ON 2000

class ControladorDeAlertas {
    public:
        ControladorDeAlertas();
        void comunicarNuevaNotificacion();
};

#endif