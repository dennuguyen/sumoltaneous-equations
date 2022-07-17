/**
 * An abstraction to let us write code to just track the opponent via ultrasonic sensing.
 */

#pragma once

#include "DistanceSensor.hpp"

class OpponentTracking {
   public:
    OpponentTracking(DistanceSensor& left_sensor, DistanceSensor& front_sensor, DistanceSensor& right_sensor, float threshold = 1000) : left_sensor(left_sensor), front_sensor(front_sensor), right_sensor(right_sensor) {
    }

    // Updates our opponent ego.
    auto update() -> void {

    }

    // Tracks the opponent. Returns the angular displacement required to place opponent in our front axis.
    auto track() -> float {

    }

    // Approaches the opponent. Returns the distance required to traverse to the opponent's position.
    auto approach() -> float {
        
    }

   private:
    float opponent_distance;  // How far the opponent is from us in mm.
    float opponent_angle;     // The angular displacement of the opponent from our front axis in degrees.
    DistanceSensor& left_sensor;
    DistanceSensor& front_sensor;
    DistanceSensor& right_sensor;
    const float threshold;
};