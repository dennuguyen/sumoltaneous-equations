/**
 * An abstraction to let us handle edge avoidance via IR sensors.
 */

#pragma once

#include "IRSensor.hpp"

class EdgeAvoidance {
   public:
    EdgeAvoidance(IRSensor& left_sensor, IRSensor& right_sensor) : left_sensor(left_sensor), right_sensor(right_sensor) {}

    auto avoid() -> int {
        auto const left_value = left_sensor.read();
        auto const right_value = right_sensor.read();
        if (left_value && right_value) {
            return 0;
        } else if (left_value) {
            return -1;
        } else if (right_value) {
            return -3;
        }
    }

   private:
    IRSensor& left_sensor;
    IRSensor& right_sensor;
};