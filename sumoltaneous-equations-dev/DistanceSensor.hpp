#pragma once

#include <Arduino.h>

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin, unsigned max_distance = 0.004)
        : trigger_pin(trigger_pin), echo_pin(echo_pin), max_distance(max_distance) {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    // double echo() {
    //     digitalWrite(trigger_pin, false);
    //     delayMicroseconds(2);
    //     digitalWrite(trigger_pin, true);
    //     delayMicroseconds(10);
    //     digitalWrite(trigger_pin, false);
    //     return pulseIn(echo_pin, HIGH) / 58.8235;
    // }

    // returns distance in cm as a float
    float dist() {
        digitalWrite(trigger_pin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigger_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigger_pin, LOW);
        noInterrupts();
        float d = pulseIn(echo_pin, HIGH, 23529.4); // max sensor dist ~4m
        interrupts();
        return d / 58.8235;
    }

   private:
    unsigned trigger_pin;
    unsigned echo_pin;
    unsigned max_distance;
};
