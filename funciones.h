#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "mbed.h"

// Definición de pines (ajusta estos pines según tu hardware)
#define PIN_BOTON_PRUEBA_BUZZER BUTTON1 // Cambia a tu pin específico
#define PIN_BOTON_PRUEBA_VENTILADOR D6 // Cambia a tu pin específico
// Configuración de objetos
extern InterruptIn boton_prueba_buzzer;
extern InterruptIn boton_prueba_ventilador;
extern bool sobretemp;

//Estado del sistema
enum Estado {
    INICIAL,
    OPTIMO,
    ALARMA,
    PRUEBA_MANUAL_BUZZER,
    PRUEBA_MANUAL_VENTILADOR
};

extern Estado estado_actual;
extern Estado estado_anterior;
extern volatile bool boton_prueba_buzzer_estado;
extern volatile bool boton_prueba_ventilador_estado;

// Prototipos de funciones
extern void cambiar_estado(Estado nuevo_estado);
//extern void controlar_invernadero(void);
extern bool temperatura_dentro_rango(void);
extern bool temperatura_sobre_umbral(void);
extern bool boton_prueba_buzzer_presionado(void);
extern bool boton_prueba_ventilador_presionado(void);
extern void manejar_boton_prueba_buzzer(void);
extern void manejar_boton_prueba_ventilador(void);
//extern void config_interrup_botones(void);

#endif //FUNCIONES_H