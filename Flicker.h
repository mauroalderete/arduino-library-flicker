#ifndef _FLICKER_HPP_
#define _FLICKER_HPP_

#include "Arduino.h"

/* @brief Posibles estados del objeto Flicker
*/
enum class FlickerState {
    STOP, 
    PAUSE, 
    START
}; 

/* @brief Una clase que permite controlar el parpadeo de una salida digital sin bloquear el flujo del programa.
*/
class Flicker
{
private:
    uint8_t _pin;
    unsigned long _interval;
    unsigned long lapsed;
    bool status;
    FlickerState state;

public:
    Flicker();
    Flicker(uint8_t pin, unsigned long interval);
    ~Flicker();

    uint8_t getPin();
    void setPin(uint8_t pin);

    unsigned long getInterval();
    
    /* @brief Configura la duracion del nivel alto y del nivel bajo de la señal en milisegundos
    */
    void setInterval(unsigned long interval);

    /* @brief Devuelve el estado del objeto: Detenido, pausado o iniciado.
    */
    FlickerState getState();

    /* @brief Devuelve el actual estado HIGH o LOW de la señal.
    */
    int getStatus();

    /* @brief Inicia el parpadeo.
    */
    void start();

    /* @brief Detiene el parpadeo sin reiniciar el estado de las variables de control.
    */
    void pause();

    /* @brief Reinicia el parpadeo desde donde lo dejo.
    */
    void resume();

    /* @brief Detiene y reinicia las varaibles asociadas al control del parpadeo.
    */
    void stop();

    /* @brief Ejecuta un ciclo del parpadeo. Es obligatorio ubicarlo en la función loop.
    */
    void loop();

};

#endif