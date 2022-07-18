/**
 * Controls a motor with three pins:
 *  - enable_pin: accepts PWM value for motor speed in range [0, 255].
 *  - input1_pin: accepts HIGH or LOW value for motor spin direction.
 *  - input2_pin: accepts HIGH or LOW value for motor spin direction.
 *
 * If the given PWM value is outside the range, the motor does not run.
 */

#pragma once

#include <Arduino.h>
#include <math.h>

class Motor {
   public:
    Motor(unsigned enable, unsigned input1_pin, unsigned input2_pin, float velocity_to_pwm_constant = 1, bool direction = 0)
        : enable_pin(enable), input1_pin(input1_pin), input2_pin(input2_pin), direction(direction), velocity_to_pwm_constant(velocity_to_pwm_constant) {
        pinMode(enable_pin, OUTPUT);
        pinMode(input1_pin, OUTPUT);
        pinMode(input2_pin, OUTPUT);
    }

    // Generic function to drive the motor.
    // 1 ^ 1, 1 ^ 0 = 0, 1
    // 1 ^ 0, 1 ^ 1 = 1, 0
    // 0 ^ 0, 0 ^ 1 = 0, 1
    // 0 ^ 1, 0 ^ 0 = 1, 0
    auto set_velocity(float angular_velocity) const -> void {
        auto change_direction = angular_velocity < 0 ? true : false;
        set(velocity_to_pwm(angular_velocity), change_direction ^ direction, change_direction ^ !direction);
    }

    auto forward() const -> void {
        set(255, direction, !direction);
    }

    auto reverse() const -> void {
        set(255, !direction, direction);
    }

    auto stop() const -> void {
        set(0, direction, direction);
    }

   private:
    // Converts an angular_velocity to PWM signal.
    // We do this because the motors are controlled directly by a PWM signal.
    auto velocity_to_pwm(float angular_velocity) const -> unsigned {
        return velocity_to_pwm_constant * abs(angular_velocity);
    }

    auto set(unsigned pwm, bool in1, bool in2) const -> void {
        analogWrite(enable_pin, pwm);
        digitalWrite(input1_pin, in1);
        digitalWrite(input2_pin, in2);
    }

    const float velocity_to_pwm_constant;
    const unsigned enable_pin;
    const unsigned input1_pin;
    const unsigned input2_pin;
    const bool direction = 0;  // Swap polarity of direction if electronics are wired differently.
};
