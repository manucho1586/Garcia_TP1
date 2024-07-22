#ifndef BOTONES_H
#define BOTONES_H

#include "mbed.h"
//**********Declaracion de botones buzzer y ventilador**********************//
 extern DigitalOut buzzer;
 extern DigitalOut ventilador;
 extern DigitalIn boton_buzzer; 
 extern DigitalIn boton_ventilador;
 //************************************************************************//


extern UnbufferedSerial pc;              //Configuración de comunicación serie a través de la UART.
                                        // Establecimiento de configuraciones (9600-8-N-1).
extern void inicializacion_uart(void);

extern Ticker ticker1;                 //Instanciación de variable tipo Ticker para manejar la función de presioanr el botón del ventilador.
extern Ticker ticker2;                 //Instanciación de variable tipo Ticker para manejar la función de presioanr el botón del buzzer.
extern void temporizador_botones(void);
 
 extern void check_boton_buzzer();
 extern void check_boton_ventilador();

#endif //BOTONES_H