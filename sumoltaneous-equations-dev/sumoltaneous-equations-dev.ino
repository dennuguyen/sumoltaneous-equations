#include "motor.hpp"

Motor left_motor(1, 2, 3);
Motor right_motor(1, 4, 5);

void setup() {
}

void loop() {
    right_motor.forward();
    delay(1000);
    right_motor.reverse();
    delay(1000);
    right_motor.stop();
    delay(1000);
}