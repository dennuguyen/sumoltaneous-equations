/**
 * Controls a motor with three pins:
 *  - enable_pin: accepts PWM value for motor speed in range [0, 255].
 *  - input1_pin: accepts HIGH or LOW value for motor spin direction.
 *  - input2_pin: accepts HIGH or LOW value for motor spin direction.
 */

#pragma once

#include <Arduino.h>

class Motor {
   public:
    Motor(unsigned enable, unsigned input1_pin, unsigned input2_pin, bool direction = 0)
        : enable_pin(enable), input1_pin(input1_pin), input2_pin(input2_pin), direction(direction) {
        pinMode(enable_pin, OUTPUT);
        pinMode(input1_pin, OUTPUT);
        pinMode(input2_pin, OUTPUT);
    }

    auto forward(unsigned pwm = 255) const -> void {
        set(pwm, direction, !direction);
    }

    auto reverse(unsigned pwm = 255) const -> void {
        set(pwm, !direction, direction);
    }

    auto stop() const -> void {
        set(0, direction, direction);
    }

   private:
    auto set(unsigned pwm, bool in1, bool in2) const -> void {
        analogWrite(enable_pin, pwm);
        digitalWrite(input1_pin, in1);
        digitalWrite(input2_pin, in2);
    }

    unsigned enable_pin;
    unsigned input1_pin;
    unsigned input2_pin;
    bool direction = 0;  // Swap polarity of direction if electronics are wired differently.
};
