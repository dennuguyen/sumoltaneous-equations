#include <Arduino.h>

/**
 * Pin has a pin number and value.
 */
struct Pin {
    Pin(int pno) : pno(pno), val(LOW) {}
    int pno;  // pin number
    int val;  // pin value
};

/**
 * Wheels are driven by a DC motor which are encoded by two pins to give three
 * possible states: forward, backward, brake.
 */
struct Wheel {
    Wheel(int in1, int in2) : in1(Pin(in1)), in2(Pin(in2)) {}
    void forward(void) {
        in1.val = HIGH;
        in2.val = LOW;
    }
    void backward(void) {
        in1.val = LOW;
        in2.val = HIGH;
    }
    void brake(void) {
        in1.val = LOW;
        in2.val = LOW;
    }
    Pin in1;
    Pin in2;
};

/**
 * Our bot only has four wheels.
 */
struct Bot {
    Bot(int lf1, int lf2, int rf1, int rf2, int lb1, int lb2, int rb1, int rb2)
        : lf(Wheel(lf1, lf2)), rf(Wheel(rf1, rf2)), lb(Wheel(lb1, lb2)), rb(Wheel(rb1, rb2)) {}
    void forward(void) {
        lf.forward();
        rf.forward();
        lb.forward();
        rb.forward();
    }
    void backward(void) {
        lf.backward();
        rf.backward();
        lb.backward();
        rb.backward();
    }
    void brake(void) {
        lf.brake();
        rf.brake();
        lb.brake();
        rb.brake();
    }
    void left(void) {
        lf.backward();
        rf.forward();
        lb.backward();
        rb.forward();
    }
    void right(void) {
        lf.forward();
        rf.backward();
        lb.forward();
        rb.backward();
    }
    void write(void) {
        digitalWrite(lf.in1.pno, lf.in1.val);
        digitalWrite(lf.in2.pno, lf.in2.val);
        digitalWrite(rf.in1.pno, rf.in1.val);
        digitalWrite(rf.in2.pno, rf.in2.val);
        digitalWrite(lb.in1.pno, lb.in1.val);
        digitalWrite(lb.in2.pno, lb.in2.val);
        digitalWrite(rb.in1.pno, rb.in1.val);
        digitalWrite(rb.in2.pno, rb.in2.val);
    }
    Wheel lf;
    Wheel rf;
    Wheel lb;
    Wheel rb;
};

Bot b(PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7);

void setup() {
    pinMode(2, OUTPUT);  // ?
    pinMode(PD0, OUTPUT);
    pinMode(PD1, OUTPUT);
    pinMode(PD2, OUTPUT);
    pinMode(PD3, OUTPUT);
    pinMode(PD4, OUTPUT);
    pinMode(PD5, OUTPUT);
    pinMode(PD6, OUTPUT);
    pinMode(PD7, OUTPUT);
}

void loop() {
    // Algorithm.
    /**
     * if (found) do something
     * else search pattern
     */

    // Write-out pins.
    b.write();
    delay(50);
}