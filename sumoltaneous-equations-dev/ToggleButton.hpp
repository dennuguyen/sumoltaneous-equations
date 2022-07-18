/**
 * ToggleButton is responsible for handling button input connected via GPIO.
 *
 * ToggleButton can keep track of button state depending on the odd number of times it has been pressed.
 *
 * ToggleButton can handle debouncing.
 */

#pragma once

#include <Arduino.h>

class ToggleButton {
   public:
    ToggleButton(unsigned pullup_pin, unsigned long debounce_period = 200UL) : pullup_pin(pullup_pin), state(false), time_of_state_change(0), debounce_period(debounce_period) {
        pinMode(pullup_pin, INPUT_PULLUP);
    }

    auto read() -> bool {
        if (digitalRead(pullup_pin) == HIGH && millis() - time_of_state_change > debounce_period) {
            state = ~state;
        }
        return state;
    }

   private:
    unsigned pullup_pin;
    bool state;
    unsigned long time_of_state_change;
    unsigned long debounce_period;
};