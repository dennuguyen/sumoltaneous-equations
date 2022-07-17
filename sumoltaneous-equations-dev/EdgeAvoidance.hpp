/**
 * An abstraction to let us handle edge avoidance via IR sensors.
 */

#pragma once

#include "IRSensor.hpp"

class EdgeAvoidance {
    public:
    EdgeAvoidance(IRSensor& left_sensor, IRSensor& right_sensor) : left_sensor(left_sensor), right_sensor(right_sensor) {}

    auto do_something() -> float {
        
    }

    private:
    IRSensor& left_sensor;
    IRSensor& right_sensor;
};