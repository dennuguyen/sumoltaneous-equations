#pragma once

#include <Arduino.h>

class IRSensor {
   public:
    IRSensor(unsigned read_pin) : read_pin(read_pin) {
        pinMode(read_pin, INPUT);
    }

    auto read() -> bool {
        return digitalRead(read_pin);
    }

   private:
    const unsigned read_pin;
};