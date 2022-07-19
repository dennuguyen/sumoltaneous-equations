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
    ToggleButton(unsigned pullup_pin, unsigned long debounce_period = 200UL) : pullup_pin(pullup_pin), previous_button_state(false), state(false), time_of_state_change(0), debounce_period(debounce_period) {
        pinMode(pullup_pin, INPUT_PULLUP);
    }

    auto read() -> bool {
        auto const current_button_state = digitalRead(pullup_pin);

        // Unpressed button returns HIGH read.
        // Pressed button returns LOW read.
        if (previous_button_state == HIGH && current_button_state == LOW && millis() - time_of_state_change > debounce_period) {
            state = !state;
            time_of_state_change = millis();
        }

        previous_button_state = current_button_state;

        return state;
    }

    auto await(bool state_progress_condition) -> void {
        while (read() != state_progress_condition) {}
    }

   private:
    const unsigned pullup_pin;
    bool previous_button_state;
    bool state;
    unsigned long time_of_state_change;
    const unsigned long debounce_period;
};