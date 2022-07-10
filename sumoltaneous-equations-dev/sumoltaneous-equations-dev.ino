#include <array>

#include "DifferentialRobot.hpp"
#include "DistanceSensor.hpp"
#include "Drive.hpp"
#include "IRSensor.hpp"
#include "Motor.hpp"

Motor left_motor(1 /* D1/TX */, 19 /* AO/D14 */, 20 /* A1/D15 */);
Motor right_motor(1 /* D1/TX */, 21 /* A2/D16 */, 22 /* A3/D17 */);
Drive drive_model(left_motor, right_motor);

DistanceSensor left(5 /* D2 */, 6 /* ~D3 */);
DistanceSensor front(7 /* D4 */, 8 /* ~D5 */);
DistanceSensor right(10 /* D7 */, 9 /* ~D6 */);
IRSensor ir_sensor(11 /* D8 */, &(drive_model.turn_left));

void setup() {
}

void loop() {
    if (front.echo()) {
        drive_model.forward();
    } else if (left.echo()) {
        drive_model.turn_left();
    } else if (right.echo()) {
        drive_model.turn_right();
    } else {
        drive_model.turn_left();
    }

    printf("%d\n", front.echo());
    delay(1000);
}
