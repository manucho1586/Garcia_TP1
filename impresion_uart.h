#ifndef IMPRESION_UART_H
#define IMPRESION_UART_H

#include "dht11.h"
#include "mbed.h"

extern UnbufferedSerial pc;              //Configuración de comunicación serie a través de la UART.
                                        // Establecimiento de configuraciones (9600-8-N-1).
void inicializacion_uart(void);

extern int tiempo_acumulado;             
extern int tiempo_incremento;
extern char buffer[16];  //Buffer donde se almacenará los bytes de datos de temperatura y humedad.
extern int Lectura;      //Variable donde se guardan los datos traidos por la función "readData()".     

void transmision_uart(void);
void temporizacion_impresion(void);

#endif //IMPRESION_UART_H