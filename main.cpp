#include "mbed.h"
#include "dht11.h"
#include "arm_book_lib.h"
#include "botones.h"
#include "lectura_temp.h"
#include "impresion_uart.h"


int main()
{
    inicializacion_uart();              //Configuración e inicialización UART.
    chequeo_botones_presionados();      //Función que contiene la asociación de las funciones de
                                        //chequeo de botones presionados con la función Ticker.
    while (true)
    {
        control_invernadero();          //Función que permite cambiar de un estado a otro en función
                                        //de la temperatura.
        transmision_uart();             //Función que permite transmitir a través de la UART
                                        //los datos de temperatura y humedad.
        temporizacion_impresion();      //Función de temporización para la impresión de los datos.
    }
}
