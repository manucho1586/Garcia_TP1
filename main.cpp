#include "mbed.h"
#include "dht11.h"
#include "arm_book_lib.h"
#include <cstdint>
#include "botones.h"
#include "lectura_temp.h"
#include "impresion_uart.h"
#include "funciones.h"



void controlar_invernadero(void);



int main()
{

    //config_interrup_botones();
    boton_prueba_buzzer.fall(&manejar_boton_prueba_buzzer);
    boton_prueba_buzzer.rise(&manejar_boton_prueba_buzzer);
    boton_prueba_ventilador.fall(&manejar_boton_prueba_ventilador);
    boton_prueba_ventilador.rise(&manejar_boton_prueba_ventilador);

    //inicializacion_uart();
    //temporizador_botones();

//**********Declaracion de entradas y salidas*******************************//
    //DHT11 sensordht(D2);                           //Instancia de una variable de tipo DHT11.
    //DigitalIn boton_buzzer(BUTTON1);             //Boton para activar o desactivar el buzzer.
    //DigitalIn boton_ventilador(D6);              //Boton para activar o desactivar el ventilador.
    //DigitalOut LED_rojo(LED1);                     //LED indicador de sobretemperatura.
    //DigitalOut LED_verde(D3);                      //LED indicador de condiciones de temperatura y humedad normales.
    //DigitalOut ventilador(D4);                   //Salida para activar el ventilador.
    //DigitalOut buzzer(D5);                       //Salida para activar el buzzer.
//**************************************************************************//

//*********Declaración de variables e inicialización de entradas-salidas****//
    //char buffer[16];                               //Buffer donde se almacenará los bytes de datos de temperatura y humedad.
    //int Lectura;                                   //Variable donde se guardan los datos traidos por la función "readData()".     
    //int umbral=22;                                 //Valor umbral de temperatura.
    //int tiempo_acumulado=0;             
    //int tiempo_incremento=1;
    //int cont=0;                                  //Contador para función antirrebote al presionar botones.
    //LED_rojo=OFF;                                  //LED indicador de alarma.
    //LED_verde=ON;                                  //LED indicador de funcionamiento en condiciones normales.
    //ventilador=LOW;         
    //buzzer=LOW;                                    //Apagado
//***************************************************************************//

//************************LOOP PRINCIPAL*************************************//
    while (true)
    {
        lectura_sensor();
        transmision_uart();
///***************************************************************///       
        delay(1); //delay de 1 ms
        tiempo_acumulado=tiempo_acumulado + tiempo_incremento;



        controlar_invernadero();
        if (boton_prueba_buzzer_presionado()) 
        {
            cambiar_estado(PRUEBA_MANUAL_BUZZER);
        } else if (boton_prueba_ventilador_presionado()) 
        {
            cambiar_estado(PRUEBA_MANUAL_VENTILADOR);
        }
        thread_sleep_for(50); // Ajusta el tiempo de espera según sea necesario
    }
}


// Función principal de control del invernadero
void controlar_invernadero(void) 
{
    switch (estado_actual) 
    {
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
            LED_verde=ON;
            LED_rojo=OFF;
            buzzer=LOW;
            ventilador=LOW;
            if (temperatura_sobre_umbral()) 
            {
                cambiar_estado(ALARMA);
            }
            break;

        case ALARMA:
            LED_verde=OFF;
            LED_rojo=ON;
            buzzer=HIGH;
            ventilador=HIGH;
            if (temperatura_dentro_rango()) 
            {
                cambiar_estado(OPTIMO);
            }
            break;

        case PRUEBA_MANUAL_BUZZER:
            buzzer=HIGH;
            if (!boton_prueba_buzzer_presionado()) 
            {
                cambiar_estado(estado_anterior);
            }
            break;

        case PRUEBA_MANUAL_VENTILADOR:
            ventilador=HIGH;
            if (!boton_prueba_ventilador_presionado()) 
            {
                cambiar_estado(estado_anterior);
            }
            break;
    }
}