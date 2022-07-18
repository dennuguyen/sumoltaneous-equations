#include <Arduino.h>

#include "DistanceSensor.hpp"
#include "Drive.hpp"
#include "IRSensor.hpp"
#include "Motor.hpp"

Motor left_motor(10, A2, A3);
Motor right_motor(11, A0, A1);
Drive drive_model(left_motor, right_motor, 65, 160);

DistanceSensor left(2, 3);
DistanceSensor front(4, 5);
DistanceSensor right(7, 6);
IRSensor ir_sensor(8);

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Old janky code.
    // if (!ir_sensor.read()) {
    //     drive_model.reverse();
    // } else if (front.echo() < 1000) {
    //     drive_model.forward();
    // } else if (left.echo() < 1000) {
    //     drive_model.turn_left();
    // } else if (right.echo() < 1000) {
    //     drive_model.turn_right();
    // } else {
    //     drive_model.turn_left();
    // }

    // Get the command to avoid the edge. This is prioritised before other plans.

    // Get the command to attack the opponent.

    // Execute the command.
    drive_model.inverse_kinematics(255, 0);
}
