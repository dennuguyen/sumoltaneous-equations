#include <Arduino.h>

#include "DistanceSensor.hpp"
#include "Drive.hpp"
#include "EdgeAvoidance.hpp"
#include "IRSensor.hpp"
#include "Motor.hpp"
#include "ToggleButton.hpp"

Motor left_motor(10, A2, A3);
Motor right_motor(11, A0, A1);
Drive drive_model(left_motor, right_motor, 65, 160);

DistanceSensor left_distance_sensor(2, 3);
DistanceSensor front_distance_sensor(4, 5);
DistanceSensor right_distance_sensor(7, 6);

IRSensor left_ir_sensor(8);
// IRSensor right_ir_sensor(9);
// EdgeAvoidance edge_avoidance(left_ir_sensor, right_ir_sensor);

ToggleButton button(12);

void setup() {
    Serial.begin(9600);
    button.await(true);
    delay(5000);
}

void loop() {
    if (left_ir_sensor.read()) {
        drive_model.reverse();
        delay(200);
    } else if (front_distance_sensor.echo() < 800) {
        drive_model.forward();
    } else if (left_distance_sensor.echo() < 800) {
        drive_model.turn_left();
    } else if (right_distance_sensor.echo() < 800) {
        drive_model.turn_right();
    } else {
        drive_model.turn_left();
    }

    if (button.read() == false) {
        drive_model.stop();
        button.await(true);
        delay(5000);
    }
}
