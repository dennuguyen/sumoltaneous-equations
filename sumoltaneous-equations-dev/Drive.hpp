#pragma once

#include "Motor.hpp"

class Drive {
   public:
    Drive(Motor& left_motor, Motor& right_motor) : left_motor_(left_motor), right_motor_(right_motor) {}

    friend auto forward(Drive& obj) -> void {
        obj.left_motor_.forward();
        obj.right_motor_.forward();
    }

    friend auto reverse(Drive& obj) -> void {
        obj.left_motor_.reverse();
        obj.right_motor_.reverse();
    }

    friend auto turn_left(Drive& obj) -> void {
        obj.left_motor_.reverse();
        obj.right_motor_.forward();
    }

    friend auto turn_right(Drive& obj) -> void {
        obj.left_motor_.forward();
        obj.right_motor_.reverse();
    }

    friend auto stop(Drive& obj) -> void {
        obj.left_motor_.stop();
        obj.right_motor_.stop();
    }

   private:
    Motor& left_motor_;
    Motor& right_motor_;
};

// Enable argument dependent lookup.
auto forward(Drive& obj) -> void;
auto reverse(Drive& obj) -> void;
auto turn_left(Drive& obj) -> void;
auto turn_right(Drive& obj) -> void;
auto stop(Drive& obj) -> void;