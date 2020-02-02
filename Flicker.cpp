#include "Arduino.h"
#include "Flicker.h"

Flicker::Flicker() {
/*    this.setPin(0);
    this.setInterval(0);
    this.stop();
    this.status = false;
    */
}
/*
Blink::Blink(uint8_t pin, unsigned long interval)
{
    this.setPin(pin);
    this.setInterval(interval);
    this.stop();
    this.status = false;
    digitalWrite(this._pin, LOW);
}
*/
Flicker::~ Flicker()
{
}
/*
void Blink::setPin(uint8_t pin){
    this._pin = pin;
    pinMode(this._pin, OUTPUT);
}

uint8_t getPin(){
    return this._pin;
}
*/
void Flicker::setInterval(unsigned long interval){
    _interval = interval;
}

unsigned long Flicker::getInterval(){
    return _interval;
}
/*
int Blink::getStatus(){
    return this.status? 1: 0;
}

BlinkState Blink::getState(){
    return this.state;
}

void Blink::start(){
    this.state = BlinkState::START;
    this.lapsed = 0;
}

void Blink::pause(){
    this.state = BlinkState::PAUSE;
}

void Blink::resume(){
    this.state = BlinkState::START;
}

void Blink::stop(){
    this.state = BlinkState::STOP;
    this.lapsed = 0;
}

void Blink::loop(){
    if ( this.state == BlinkState::START ) {
        unsigned long current = millis();
        if ( current - this.lapsed >= this._interval ) {
            this.lapsed = current;

            this.status = !this.status;
            if (this.status) {
                digitalWrite(this._pin, HIGH);
            } else {
                digitalWrite(this._pin, LOW);
            }
        }
    }
}
*/