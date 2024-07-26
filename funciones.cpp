#include "mbed.h"
#include "dht11.h"
#include "arm_book_lib.h"
#include <cstdint>
#include "botones.h"
#include "lectura_temp.h"
#include "impresion_uart.h"




// Funciones de manejo de botones
void manejar_boton_prueba_buzzer() 
{
    boton_prueba_buzzer_estado = !boton_prueba_buzzer_estado;
}

void manejar_boton_prueba_ventilador() 
{
    boton_prueba_ventilador_estado = !boton_prueba_ventilador_estado;
}

// Funciones para verificar el estado de los botones de prueba
bool boton_prueba_buzzer_presionado() 
{
    return boton_prueba_buzzer_estado;
}

bool boton_prueba_ventilador_presionado() 
{
    return boton_prueba_ventilador_estado;
}

// Función para cambiar el estado del sistema
void cambiar_estado(Estado nuevo_estado) 
{
    estado_anterior = estado_actual;
    estado_actual = nuevo_estado;
}

// Función principal de control del invernadero
void controlar_invernadero() 
{
    switch (estado_actual) {
        case INICIAL:
            if (temperatura_dentro_rango()) 
            {
                cambiar_estado(OPTIMO);
            } else if (temperatura_sobre_umbral()) 
            {
                cambiar_estado(ALARMA);
            }
            break;

        case OPTIMO:
            encender_led_verde();
            apagar_led_rojo();
            apagar_buzzer();
            apagar_ventilador();
            if (temperatura_sobre_umbral()) 
            {
                cambiar_estado(ALARMA);
            }
            break;

        case ALARMA:
            apagar_led_verde();
            encender_led_rojo();
            encender_buzzer();
            encender_ventilador();
            if (temperatura_dentro_rango()) 
            {
                cambiar_estado(OPTIMO);
            }
            break;

        case PRUEBA_MANUAL_BUZZER:
            encender_buzzer();
            if (!boton_prueba_buzzer_presionado()) 
            {
                cambiar_estado(estado_anterior);
            }
            break;

        case PRUEBA_MANUAL_VENTILADOR:
            encender_ventilador();
            if (!boton_prueba_ventilador_presionado()) 
            {
                cambiar_estado(estado_anterior);
            }
            break;
    }
}

// Implementaciones de funciones auxiliares (adaptar según sea necesario)
bool temperatura_dentro_rango() 
{
    if(sensordht.readTemperature()<umbral)     //Condición de sobretemperatura.
    sobretemp=false;
    return sobretemp;
}

bool temperatura_sobre_umbral() 
{
    if(sensordht.readTemperature()>umbral)     //Condición de sobretemperatura.
    sobretemp=true;
    return sobretemp;

void encender_led_verde() 
{
    LED_verde=ON;
}

void apagar_led_verde() 
{
    LED_verde=OFF;
}

void encender_led_rojo() 
{
    LED_rojo=ON;
}

void apagar_led_rojo() 
{
    LED_rojo=OFF;
}

void encender_buzzer() 
{
    buzzer=HIGH;
}

void apagar_buzzer() 
{
    buzzer=LOW;
}

void encender_ventilador() 
{
    ventilador=HIGH;
}

void apagar_ventilador() 
{
    ventilador=LOW;
}
