#ifndef IMPRESION_UART_H
#define IMPRESION_UART_H

#include "dht11.h"
#include "mbed.h"


extern int tiempo_acumulado;             
extern int tiempo_incremento;
extern char buffer[16];                               //Buffer donde se almacenará los bytes de datos de temperatura y humedad.
extern int Lectura;                                   //Variable donde se guardan los datos traidos por la función "readData()".     

extern void transmision_uart(void);

#endif //IMPRESION_UART_H