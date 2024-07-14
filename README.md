# **<u>Trabajo Práctico N° 1</u>**
___
Para este primer trabajo se tuvieron en cuenta los 3 primeros cápitulos del libro utilizado en el curso, donde se abordaron temas como manejo entradas y salidas digitales, manejo del tiempo de ejecucion y retardos por software y señales analógicas, también otros puntos importantes como modularización y forma prolija de escribir el código fuente para que pueda ser más mantenible y reutilizable.

Para poder llevar a cabo el objetivo planteado en la consigna del trabajo práctico, se trabajó con una libreria para el sensor de temperatura y humedad DHT11. En el siguiente link se encuentra el repositorio original del código utilizado:
https://os.mbed.com/users/s_inoue_mbed/code/DHT11/docs/tip/classDHT11.html

Se pudo cumplir con el funcionamiento planteado, el cual era imprimir los valores de temperatura y humedad a través del monitor del puerto serie, comparar el valor de temperatura con un umbral establecido y si la temperatura era superior a dicho umbral se prendian las alarmas (LED indicador y buzzer) y el ventilador. En caso contrario, las alarmas y el ventilador se mantenian apagados y hay un LED verde indicador de condiciones normales. Además se contaba con dos botones, uno para la activación/desactivación del buzzer y otro para el ventilador. 

**Captura del monitor de la comunicación serie:**  
  
![Captura](file:///D:/Curso%20de%20Sistemas%20Embebidos%20FIUBA/TP's/Resolución%20del%20TP/Captura.PNG)

Para ver video del funcionamiento del sistema implementado: 
https://drive.google.com/drive/u/0/folders/1Rxv_zzBpI5dtSBoAziEq5WgmIlY6Kuhn
