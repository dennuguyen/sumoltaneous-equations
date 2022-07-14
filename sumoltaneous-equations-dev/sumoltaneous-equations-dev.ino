#include <Arduino.h>

#include "DistanceSensor.hpp"
#include "Drive.hpp"
#include "IRSensor.hpp"
#include "Motor.hpp"

Motor left_motor(1, A0, A1);
Motor right_motor(1, A2, A3);
Drive drive_model(left_motor, right_motor);

DistanceSensor left(2, 3);
DistanceSensor front(4, 5);
DistanceSensor right(7, 6);
IRSensor ir_sensor(8);

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (ir_sensor.read()) {
        reverse(drive_model);
    } else if (front.echo()) {
        forward(drive_model);
    } else if (left.echo()) {
        turn_left(drive_model);
    } else if (right.echo()) {
        turn_right(drive_model);
    } else {
        turn_left(drive_model);
    }
}
