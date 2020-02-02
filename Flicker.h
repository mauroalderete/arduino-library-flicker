#ifndef _FLICKER_HPP_
#define _FLICKER_HPP_

#include "Arduino.h"

/* Hace que un pin, led, parpadee sin blockeo de codigo. Utiliza la funcion milis
*/

enum class FlickerState {
    STOP, 
    PAUSE, 
    START
}; 

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
    void setInterval(unsigned long interval);

    FlickerState getState();
    int getStatus();

    void start();
    void pause();
    void resume();
    void stop();

    void loop();

};

#endif