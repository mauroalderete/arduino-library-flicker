#include "Arduino.h"
#include "Flicker.h"

Flicker::Flicker() {
    SetPin(0);
    SetInterval(0);
    Stop();
    status = false;
}

Flicker::Flicker(uint8_t pin, unsigned long interval)
{
    SetPin(pin);
    SetInterval(interval);
    Stop();
    status = false;
    digitalWrite(_pin, LOW);
}

Flicker::~ Flicker()
{
    Stop();
}

void Flicker::SetPin(uint8_t pin){
    _pin = pin;
    pinMode(_pin, OUTPUT);
}

uint8_t Flicker::GetPin(){
    return _pin;
}

void Flicker::SetInterval(unsigned long interval){
    _interval = interval;
}

unsigned long Flicker::GetInterval(){
    return _interval;
}

int Flicker::GetStatus(){
    return status? 1: 0;
}

FlickerState Flicker::GetState(){
    return state;
}

void Flicker::Start(){
    state = FlickerState::START;
    lapsed = millis();
}

void Flicker::Pause(){
    state = FlickerState::PAUSE;
}

void Flicker::Resume(){
    state = FlickerState::START;
}

void Flicker::Stop(){
    state = FlickerState::STOP;
    lapsed = 0;
}

void Flicker::Loop(){
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
