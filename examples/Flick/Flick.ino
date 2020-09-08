/*
    Flick LED

    Este ejemplo muestra como implementar un led parpadeante de manera simple utilizando la libreria Flicker.
    El objeto flick se inicializa indicando dos parametros:
    - Primer parametro: Pin digital que se busca que parpadee
    - Segundo parametro: Milisegundo que durará el encendido y el apagado.

    Al construir flick con esos parametros, inmediatamente realiza la configuración del modo del pin.
    Luego en el setup se puede iniciar la cuenta.

    Hay que tener presente que debe ejecutarse el metodo Loop() dentro de loop() para que en cada iteración pueda calcular los intervalos de tiempos y hacer parpadear la salida.
*/
#include <Arduino.h>
#include <Flicker.h>

Flicker flick(LED_BUILTIN, 1000);

void setup(){
    flick.Start();
}

void loop(){
    flick.Loop();
}