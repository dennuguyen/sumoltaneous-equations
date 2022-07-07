#pragma once

#include <Arduino.h>

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin)
        : trigger_pin(trigger_pin), echo_pin(echo_pin) {
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
        float d = pulseIn(echo_pin, HIGH, 23529.4); // max sensor dist ~4m
        interrupts();
        return d / 5.88235;
    }

   private:
    unsigned trigger_pin;
    unsigned echo_pin;
};
