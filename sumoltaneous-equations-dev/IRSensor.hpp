#pragma once

#include <Arduino.h>

class IRSensor {
   public:
    IRSensor(unsigned read_pin, void* callback = read) : read_pin(read_pin) {
        pinMode(read_pin, INPUT);
        attachInterrupt(digitalPinToInterrupt(read_pin), callback, HIGH);
    }

    void read() {
        detected = digitalRead(read_pin);
    }

    bool read() {
        return detected;
    }

   private:
    unsigned read_pin;
    bool detected;
};