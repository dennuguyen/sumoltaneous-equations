#pragma once

#include <Arduino.h>

class IRSensor {
   public:
    IRSensor(unsigned read_pin, void* callback) : read_pin(read_pin) {
        pinMode(read_pin, INPUT);
        attachInterrupt(digitalPinToInterrupt(read_pin), callback, HIGH);
    }

   private:
    const unsigned read_pin;
};