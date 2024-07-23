#include "mbed.h"
#include "dht11.h"
#include "arm_book_lib.h"
#include <cstdint>
#include "botones.h"
#include "lectura_temp.h"
#include "impresion_uart.h"

int tiempo_acumulado=0;             
int tiempo_incremento=1;
char buffer[16];                               //Buffer donde se almacenará los bytes de datos de temperatura y humedad.
int Lectura;                                   //Variable donde se guardan los datos traidos por la función "readData()".     

void transmision_uart(void)
{
    if(tiempo_acumulado==2000)            //Condición de tiempo acumulador cumplido.
    {
        Lectura=sensordht.readData();         //Lectura de datos del DHT.
        //printf("T:%d, H:%d\r\n", d.readTemperature(), d.readHumidity()); // esta instrucción ya imprime en pantala del monitor serie.
        sprintf(buffer, "T:%d, H:%d\r\n", sensordht.readTemperature(), sensordht.readHumidity());
        pc.write(buffer,16);                  //Transmisión de los datos ya convertidos a caracteres para presentar en pantalla.
        tiempo_acumulado=0;                   //Reinicio del contador de tiempo acumulador para presentar en pantalla cada 2 segundos los datos leídos del sensor.
    }
}