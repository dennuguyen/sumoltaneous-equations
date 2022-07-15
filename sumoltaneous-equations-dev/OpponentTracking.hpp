/**
 * An abstraction to let us write code to just track the opponent via ultrasonic sensing.
 */

#pragma once

#include "DistanceSensor.hpp"

class OpponentTracking {
   public:
    OpponentTracking(DistanceSensor& left_sensor, DistanceSensor& front_sensor, DistanceSensor& right_sensor, float threshold = 1000) : left_sensor(left_sensor), front_sensor(front_sensor), right_sensor(right_sensor) {
    }

   private:
    float opponent_distance;  // How far the opponent is from us in mm.
    float opponent_angle;     // The angular displacement of the opponent from our front axis in radians.
    DistanceSensor& left_sensor;
    DistanceSensor& front_sensor;
    DistanceSensor& right_sensor;
    const float threshold;
};