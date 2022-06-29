#include "DifferentialRobot.hpp"
#include "DistanceSensor.hpp"
#include "IRSensor.hpp"
#include "Motor.hpp"

DifferentialRobot robot(0.065, 0.18);
Motor left_motor(1, 19, 20);   // analog, digital, digital
Motor right_motor(1, 21, 22);  // analog, digital, digital
DistanceSensor left(5, 6);     // digital, analog
DistanceSensor front(7, 8);    // digital, analog
DistanceSensor right(10, 9);   // digital, analog
IRSensor ir_sensor(11);        // digital

void setup() {
}

void loop() {
    printf("%d\n", front.echo());
    delay(1000);
}
