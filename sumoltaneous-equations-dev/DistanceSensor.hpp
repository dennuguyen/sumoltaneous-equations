#pragma once

#include <Arduino.h>

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin, float timeout_ms = 23529.4, float ms_to_mm = 5.88235)
        : trigger_pin(trigger_pin), echo_pin(echo_pin), timeout_ms(timeout_ms), ms_to_mm(ms_to_mm) {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    // We have to call echo continuously.
    // The echo_pin can be made interruptable which interrupts the flow of the code.
    // The callback function on interrupt is the sending of a move command.

    // returns distance in mm as a float
    float echo() {
        digitalWrite(trigger_pin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigger_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigger_pin, LOW);
        noInterrupts();
        float duration_ms = pulseIn(echo_pin, HIGH, timeout_ms);
        interrupts();
        return duration_ms / ms_to_mm;
    }

   private:
    unsigned trigger_pin;
    unsigned echo_pin;
    float timeout_ms;
    float ms_to_mm;
};
