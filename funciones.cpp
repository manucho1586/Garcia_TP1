#include "mbed.h"
#include "dht11.h"
#include "arm_book_lib.h"
#include <cstdint>
#include "botones.h"
#include "lectura_temp.h"
#include "impresion_uart.h"
#include "funciones.h"

// Configuración de objetos
InterruptIn boton_prueba_buzzer(PIN_BOTON_PRUEBA_BUZZER);
InterruptIn boton_prueba_ventilador(PIN_BOTON_PRUEBA_VENTILADOR);


bool sobretemp=false;



Estado estado_actual = INICIAL;
Estado estado_anterior = INICIAL;
volatile bool boton_prueba_buzzer_estado = false;
volatile bool boton_prueba_ventilador_estado = false;



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


// Implementaciones de funciones auxiliares (adaptar según sea necesario)
bool temperatura_dentro_rango(void) 
{
    if(sensordht.readTemperature()<umbral)     //Condición de sobretemperatura.
    sobretemp=false;
    return sobretemp;
}

bool temperatura_sobre_umbral(void) 
{
    if(sensordht.readTemperature()>umbral)     //Condición de sobretemperatura.
    sobretemp=true;
    return sobretemp;
}