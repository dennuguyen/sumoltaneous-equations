#pragma once

#include <Arduino.h>

class DistanceSensor {
   public:
    DistanceSensor(unsigned trigger_pin, unsigned echo_pin, float timeout_ms = 23529.4, float ms_to_mm = 5.88235, float pulse_on_duration_ms = 10, float pulse_off_duration_ms = 2)
        : trigger_pin(trigger_pin), echo_pin(echo_pin), timeout_ms(timeout_ms), ms_to_mm(ms_to_mm), pulse_on_duration_ms(pulse_on_duration_ms), pulse_off_duration_ms(pulse_off_duration_ms) {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    // Function triggers a pulse for some number of milliseconds then returns the distance to the
    // detected obstacle or 0 otherwise.
    auto echo() const -> float {
        digitalWrite(trigger_pin, LOW);
        delayMicroseconds(pulse_off_duration_ms);
        digitalWrite(trigger_pin, HIGH);
        delayMicroseconds(pulse_on_duration_ms);
        digitalWrite(trigger_pin, LOW);
        noInterrupts();
        float duration_ms = pulseIn(echo_pin, HIGH, timeout_ms);
        interrupts();
        return duration_ms != 0 ? duration_ms / ms_to_mm : timeout_ms / ms_to_mm;
    }

   private:
    const unsigned trigger_pin;
    const unsigned echo_pin;
    const float ms_to_mm;
    const float timeout_ms;
    const float pulse_on_duration_ms;
    const float pulse_off_duration_ms;
};
