#include "Arduino.h"
#include "Flicker.h"

Flicker::Flicker() {
    setPin(0);
    setInterval(0);
    stop();
    status = false;
}

Flicker::Flicker(uint8_t pin, unsigned long interval)
{
    setPin(pin);
    setInterval(interval);
    stop();
    status = false;
    digitalWrite(_pin, LOW);
}

Flicker::~ Flicker()
{
    stop();
}

void Flicker::setPin(uint8_t pin){
    _pin = pin;
    pinMode(_pin, OUTPUT);
}

uint8_t Flicker::getPin(){
    return _pin;
}

void Flicker::setInterval(unsigned long interval){
    _interval = interval;
}

unsigned long Flicker::getInterval(){
    return _interval;
}

int Flicker::getStatus(){
    return status? 1: 0;
}

FlickerState Flicker::getState(){
    return state;
}

void Flicker::start(){
    state = FlickerState::START;
    lapsed = millis();
}

void Flicker::pause(){
    state = FlickerState::PAUSE;
}

void Flicker::resume(){
    state = FlickerState::START;
}

void Flicker::stop(){
    state = FlickerState::STOP;
    lapsed = 0;
}

void Flicker::loop(){
    if ( state == FlickerState::START ) {
        unsigned long current = millis();
        if ( current - lapsed >= _interval ) {
            lapsed = current;

            status = !status;
            if (status) {
                digitalWrite(_pin, HIGH);
            } else {
                digitalWrite(_pin, LOW);
            }
        }
    }
}
