/**
 * An abstraction to let us drive the robot via its motors.
 */

#pragma once

#include "Motor.hpp"

class Drive {
   public:
    Drive(Motor& left_motor, Motor& right_motor) : left_motor_(left_motor), right_motor_(right_motor) {}

    auto forward() -> void {
        left_motor_.forward();
        right_motor_.forward();
    }

    auto reverse() -> void {
        left_motor_.reverse();
        right_motor_.reverse();
    }

    auto turn_left() -> void {
        left_motor_.reverse();
        right_motor_.forward();
    }

    auto turn_right() -> void {
        left_motor_.forward();
        right_motor_.reverse();
    }

    auto stop() -> void {
        left_motor_.stop();
        right_motor_.stop();
    }

   private:
    Motor& left_motor_;
    Motor& right_motor_;
};
