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

    uint8_t GetPin();
    void SetPin(uint8_t pin);

    unsigned long GetInterval();
    
    /* @brief Configura la duracion del nivel alto y del nivel bajo de la señal en milisegundos
    */
    void SetInterval(unsigned long interval);

    /* @brief Devuelve el estado del objeto: Detenido, pausado o iniciado.
    */
    FlickerState GetState();

    /* @brief Devuelve el actual estado HIGH o LOW de la señal.
    */
    int GetStatus();

    /* @brief Inicia el parpadeo.
    */
    void Start();

    /* @brief Detiene el parpadeo sin reiniciar el estado de las variables de control.
    */
    void Pause();

    /* @brief Reinicia el parpadeo desde donde lo dejo.
    */
    void Resume();

    /* @brief Detiene y reinicia las varaibles asociadas al control del parpadeo.
    */
    void Stop();

    /* @brief Ejecuta un ciclo del parpadeo. Es obligatorio ubicarlo en la función loop.
    */
    void Loop();

};

#endif