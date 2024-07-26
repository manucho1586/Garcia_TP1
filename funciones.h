#ifndef FUNCIONES_H
#define FUNCIONES_H


// Definición de pines (ajusta estos pines según tu hardware)
#define PIN_BOTON_PRUEBA_BUZZER PB_0 // Cambia a tu pin específico
#define PIN_BOTON_PRUEBA_VENTILADOR PB_1 // Cambia a tu pin específico
// Configuración de objetos
InterruptIn boton_prueba_buzzer(PIN_BOTON_PRUEBA_BUZZER);
InterruptIn boton_prueba_ventilador(PIN_BOTON_PRUEBA_VENTILADOR);
bool sobretemp=false;

// Estado del sistema
enum Estado {
    INICIAL,
    OPTIMO,
    ALARMA,
    PRUEBA_MANUAL_BUZZER,
    PRUEBA_MANUAL_VENTILADOR
};

Estado estado_actual = INICIAL;
Estado estado_anterior = INICIAL;
volatile bool boton_prueba_buzzer_estado = false;
volatile bool boton_prueba_ventilador_estado = false;

// Prototipos de funciones
void cambiar_estado(Estado nuevo_estado);
void controlar_invernadero();
bool temperatura_dentro_rango();
bool temperatura_sobre_umbral();
bool boton_prueba_buzzer_presionado();
bool boton_prueba_ventilador_presionado();
void encender_led_verde();
void apagar_led_verde();
void encender_led_rojo();
void apagar_led_rojo();
void encender_buzzer();
void apagar_buzzer();
void encender_ventilador();
void apagar_ventilador();
void manejar_boton_prueba_buzzer();
void manejar_boton_prueba_ventilador();

#endif //FUNCIONES_H