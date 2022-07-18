/**
 * An abstraction to let us drive the robot via its motors.
 */

#pragma once

#include "Motor.hpp"

class Drive {
   public:
    Drive(Motor& left_motor, Motor& right_motor, float wheel_radius, float axle_length) : left_motor(left_motor), right_motor(right_motor), wheel_radius(wheel_radius), axle_length(axle_length) {}

    // Controlling the robot via linear_velocity and angular_velocity inputs.
    auto inverse_kinematics(float linear_velocity, float angular_velocity) -> void {
        const float left_wheel_velocity = (linear_velocity - axle_length * angular_velocity) / wheel_radius;
        const float right_wheel_velocity = (linear_velocity + axle_length * angular_velocity) / wheel_radius;
        drive(left_wheel_velocity, right_wheel_velocity);
    }

    // Controlling the robot via its left_wheel_velocity and right_wheel_velocity.
    auto drive(float left_wheel_velocity, float right_wheel_velocity) -> void {
        left_motor.set_velocity(left_wheel_velocity);
        right_motor.set_velocity(right_wheel_velocity);
    }

    // Convenience commands to simply drive forward, reverse, turn_left, turn_right, and stop.
    auto forward() -> void {
        left_motor.forward();
        right_motor.forward();
    }

    auto reverse() -> void {
        left_motor.reverse();
        right_motor.reverse();
    }

    auto turn_left() -> void {
        left_motor.reverse();
        right_motor.forward();
    }

    auto turn_right() -> void {
        left_motor.forward();
        right_motor.reverse();
    }

    auto stop() -> void {
        left_motor.stop();
        right_motor.stop();
    }

   private:
    // Properties of the kinematic model.
    const float wheel_radius;
    const float axle_length;

    // Motor aggregation.
    Motor& left_motor;
    Motor& right_motor;
};
