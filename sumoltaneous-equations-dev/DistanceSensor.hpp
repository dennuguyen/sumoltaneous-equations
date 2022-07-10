#pragma once

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin, unsigned max_distance = 0.004)
        : trigger_pin(trigger_pin), echo_pin(echo_pin), max_distance(max_distance) {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    // We have to call echo continuously.
    // The echo_pin can be made interruptable which interrupts the flow of the code.
    // The callback function on interrupt is the sending of a move command.
    double echo() {
        digitalWrite(trigger_pin, false);
        delayMicroseconds(2);
        digitalWrite(trigger_pin, true);
        delayMicroseconds(10);
        digitalWrite(trigger_pin, false);
        return pulseIn(echo_pin, HIGH) / 58.8235;
    }

   private:
    unsigned trigger_pin;
    unsigned echo_pin;
    unsigned max_distance;
};