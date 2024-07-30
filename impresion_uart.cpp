#include "arm_book_lib.h"
#include "dht11.h"
#include "lectura_temp.h"       //Se incluye esta cabecera porque se necesita la variable "sensordht"
#include "impresion_uart.h"

//***********Inicialización de comunicación serie**************************************************//
UnbufferedSerial pc(USBTX, USBRX);
void inicializacion_uart(void)
 {
    pc.baud(9600);
    pc.format(8, SerialBase::None, 1);
 }
//*************************************************************************************************//

//***************Declaración de variables e inicialización de entradas-salidas*********************//
int tiempo_acumulado=0; //Tiempo que tarda en imprimirse cada lectura.         
int tiempo_incremento=1;
char buffer[16];        //Buffer donde se almacenará los bytes de datos de temperatura y humedad.
int Lectura;            //Variable donde se guardan los datos traidos por la función "readData()".     
//*************************************************************************************************//
void transmision_uart(void)
{
    if(tiempo_acumulado==2000)                  //Condición de tiempo acumulador cumplido.
    {
        Lectura=sensordht.readData();           //Lectura de datos del DHT.
        sprintf(buffer, "T:%d, H:%d\r\n", sensordht.readTemperature(), sensordht.readHumidity());
        pc.write(buffer,16);                    //Transmisión de los datos ya convertidos a caracteres para presentar en pantalla.
        tiempo_acumulado=0;                     //Reinicio del contador de tiempo acumulador para presentar en pantalla cada 2 segundos los datos leídos del sensor.
    }
}

void temporizacion_impresion(void)
{
    delay(1); //delay de 1 ms
    tiempo_acumulado=tiempo_acumulado + tiempo_incremento;
}