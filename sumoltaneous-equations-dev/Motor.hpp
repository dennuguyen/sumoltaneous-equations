/**
 * Controls a motor with three pins:
 *  - enable_pin: accepts PWM value for motor speed in range [0, 255].
 *  - input1_pin: accepts HIGH or LOW value for motor spin direction.
 *  - input2_pin: accepts HIGH or LOW value for motor spin direction.
 */

#pragma once

class Motor {
   public:
    Motor(unsigned en, unsigned in1, unsigned in2, bool direction = 0)
        : enable_pin(en), input1_pin(in1), input2_pin(in2), direction(direction) {
        pinMode(enable_pin, OUTPUT);
        pinMode(input1_pin, OUTPUT);
        pinMode(input2_pin, OUTPUT);
    }

    void forward(unsigned pwm = 255) {
        set(pwm, direction, !direction);
    }

    void reverse(unsigned pwm = 255) {
        set(pwm, !direction, direction);
    }

    void stop() {
        set(0, direction, direction);
    }

   private:
    void set(unsigned pwm, bool in1, bool in2) {
        analogWrite(enable_pin, pwm);
        digitalWrite(input1_pin, in1);
        digitalWrite(input2_pin, in2);
    }

    unsigned enable_pin;
    unsigned input1_pin;
    unsigned input2_pin;
    bool direction = 0;  // Swap polarity of direction if electronics are wired differently.
};
