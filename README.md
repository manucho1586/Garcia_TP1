# **<u>Trabajo Práctico N° 2</u>**
___
En este segundo trabajo prático se siguió trabajando sobre la misma temática del trabajo práctico N°1, agregandole contenidos tratados en los capítulo 4 y 5, los cuales eran modularización de archivos y máquinas de estado finito.
Para cumplir con los objetivos consignados, se dividió en un archivo.cpp los botones (botones.cpp), en otro la comunicación a través de la UART (impresion_uart.cpp) y en otro archivo el funcionamiento del sistema (temp_lectura.cpp). Para comentar de manera breve, en el archivo temp_lectura.cpp se encuentra dentro de una función la estructura que emula a una maquina de dos estados, vale aclarar que dicha estructura, no es un switch case sino simplemente un if/else.

Para poder llevar a cabo el objetivo planteado en la consigna del trabajo práctico, se trabajó con una libreria para el sensor de temperatura y humedad DHT11. En el siguiente link se encuentra el repositorio original del código utilizado:

https://os.mbed.com/users/s_inoue_mbed/code/DHT11/docs/tip/classDHT11.html

Se pudo cumplir con el funcionamiento planteado, el cual era imprimir los valores de temperatura y humedad a través del monitor del puerto serie, comparar el valor de temperatura con un umbral establecido y si la temperatura era superior a dicho umbral se prendian las alarmas (LED indicador y buzzer) y el ventilador. En caso contrario, las alarmas y el ventilador se mantenian apagados, mientras que un LED verde indica las condiciones normales del ambiente. Además se contaba con dos botones, uno para la activación/desactivación del buzzer y otro para el ventilador, ambos de forma manual. 

**Captura del monitor de la comunicación serie:**  
  
![Captura](file:///D:/Curso%20de%20Sistemas%20Embebidos%20FIUBA/TP's/Resolución%20del%20TP/Captura.PNG)

Para ver video del funcionamiento del sistema implementado: 
https://drive.google.com/drive/u/0/folders/1Rxv_zzBpI5dtSBoAziEq5WgmIlY6Kuhn
