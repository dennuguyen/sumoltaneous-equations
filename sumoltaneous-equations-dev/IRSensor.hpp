#pragma once

class IRSensor {
   public:
    IRSensor(unsigned read_pin) : read_pin(read_pin) {
        pinMode(read_pin, INPUT);
    }

    bool read() {
        return digitalRead(read_pin);
    }

   private:
    unsigned read_pin;
};