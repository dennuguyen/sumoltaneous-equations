#pragma once

class DifferentialRobot {
   public:
    DifferentialRobot(double wheel_radius, double axle_length)
        : wheel_radius(wheel_radius), axle_length(axle_length) {}

    std::array<double, 2> forward_kinematics(std::array<double, 2> wheel_velocities) {
        double linear_velocity = wheel_radius / 2 * (wheel_velocities[0] + wheel_velocities[1]);
        double angular_velocity = wheel_radius / 2 / axle_length * (wheel_velocities[1] - wheel_velocities[0]);
        return {linear_velocity, angular_velocity};
    }

    std::array<double, 2> inverse_kinematics(std::array<double, 2> robot_velocity) {
        double left_wheel_velocity = (robot_velocity[0] - axle_length * robot_velocity[1]) / wheel_radius;
        double right_wheel_velocity = (robot_velocity[0] + axle_length * robot_velocity[1]) / wheel_radius;
    }

    // std::array<double, 3> step()

   private:
    double wheel_radius;
    double axle_length;
    double x;
    double y;
    double heading;
};
