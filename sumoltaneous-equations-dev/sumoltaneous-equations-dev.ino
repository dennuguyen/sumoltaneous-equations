#include <Arduino.h>

#include "DistanceSensor.hpp"
#include "Drive.hpp"
#include "IRSensor.hpp"
#include "Motor.hpp"
#include "ToggleButton.hpp"

Motor left_motor(10, A2, A3);
Motor right_motor(11, A0, A1);
Drive drive_model(left_motor, right_motor, 65, 160);

DistanceSensor left(2, 3);
DistanceSensor front(4, 5);
DistanceSensor right(7, 6);
IRSensor ir_sensor(8);

ToggleButton button(12);

void setup() {
    Serial.begin(9600);
    button.await(true);
    delay(700);
}

void loop() {
    if (ir_sensor.read()) {
        drive_model.reverse();
        delay(200);
    } else if (front.echo() < 800) {
        drive_model.forward();
    } else if (left.echo() < 800) {
        drive_model.turn_left();
    } else if (right.echo() < 800) {
        drive_model.turn_right();
    } else {
        drive_model.turn_left();
    }

    if (button.read() == false) {
        drive_model.stop();
        button.await(true);
        delay(1000);
    }
}
