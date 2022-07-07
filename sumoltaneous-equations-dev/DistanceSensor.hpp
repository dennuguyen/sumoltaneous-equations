#pragma once

#include <Arduino.h>

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin, float timeout = 23529.4, float time_to_mm = 5.88235)
        : trigger_pin(trigger_pin), echo_pin(echo_pin), timeout(timeout), time_to_mm(time_to_mm) {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    // returns distance in mm as a float
    float dist() {
        digitalWrite(trigger_pin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigger_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigger_pin, LOW);
        noInterrupts();
        float duration = pulseIn(echo_pin, HIGH, timeout);
        interrupts();
        return duration / time_to_mm;
    }

   private:
    unsigned trigger_pin;
    unsigned echo_pin;
    unsigned timeout;
    unsigned time_to_mm;
};
