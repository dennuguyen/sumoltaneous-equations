#pragma once

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin, unsigned max_distance)
        : trigger_pin(trigger_pin), echo_pin(echo_pin), max_distance(max_distance) {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    double echo() {
        digitalWrite(trigger_pin, false);
        delayMicroseconds(2);
        delayWrite(trigger_pin, true);
        delayMicroseconds(10);
        digitalWrite(trigger_pin, false);
        return pulseIn(echo_pin, HIGH) / 58.8235;
    }

   private:
    unsigned trigger_pin;
    unsigned echo_pin;
    unsigned max_distance;
};