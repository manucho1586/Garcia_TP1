#ifndef LECTURA_TEMP_H
#define LECTURA_TEMP_H

#include "dht11.h"
#include "mbed.h"

extern DHT11 sensordht;                           //Instancia de una variable de tipo DHT11.
extern DigitalOut LED_rojo;                     //LED indicador de sobretemperatura.
extern DigitalOut LED_verde;                      //LED indicador de condiciones de temperatura y humedad normales.
extern int umbral;                                 //Valor umbral de temperatura.

extern void lectura_sensor(void);


#endif //LECTURA_TEMP_H