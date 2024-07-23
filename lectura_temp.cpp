#include "mbed.h"
#include "dht11.h"
#include "arm_book_lib.h"
#include <cstdint>
#include "botones.h"
#include "lectura_temp.h"


DHT11 sensordht(D2);                           //Instancia de una variable de tipo DHT11.
DigitalOut LED_rojo(LED1);                     //LED indicador de sobretemperatura.
DigitalOut LED_verde(D3);                      // LED indicador de condiciones de
                                                // temperatura y humedad normales.
int umbral=22;                                 //Valor umbral de temperatura.


void lectura_sensor(void)
{
    if(sensordht.readTemperature()>umbral)     //Condición de sobretemperatura.
    {
        if(LED_rojo==OFF)                      //Se encienden alarmas (LED + buzzer) y el ventilador.
        {
            LED_rojo=ON;
            LED_verde=OFF;
            buzzer=HIGH;
            ventilador=HIGH;
        }
    }
    else                                      //Caso contrario se apagan las alarmas y se enciende LED verde.
    {
        if(LED_verde==OFF)
        {
            LED_verde=ON;
            LED_rojo=OFF;
            ventilador=LOW;
            buzzer=LOW;
        }
    }
}