#include <Arduino.h>
#include <util/twi.h>

struct Pin {
   public:
    Pin(int pno) : pno(pno), val(LOW) {}

   public:
    int pno;  // pin number
    int val;  // pin value
};

class Wheel {
   public:
    Wheel(int in1, int in2) : in1(Pin(in1)), in2(Pin(in2)) {}
    void init(void) {
        pinMode(in1.pno, OUTPUT);
        pinMode(in2.pno, OUTPUT);
    }
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

   public:
    Pin in1;
    Pin in2;
};

class Sonar {
   public:
    Sonar(int echo, int trig) : echo(echo), trig(trig) {}
    void init(void) {
        pinMode(echo.pno, INPUT);
        pinMode(trig.pno, OUTPUT);
    }
    void clear(void) {
        digitalWrite(trig.pno, LOW);
    }
    void send(void) {
        digitalWrite(trig.pno, HIGH);
    }
    double receive(void) {
        return pulseIn(echo.pno, HIGH) * 0.034 / 2;  // distance in cm
    }

   public:
    Pin echo;
    Pin trig;
};

class Infrared {
   private:
    enum colours {
        MIN = 0,
        BLACK = 900,
        MAX = 1023,
    };

   public:
    Infrared(int sig) : sig(sig) {}
    void init(void) {
        pinMode(sig.pno, INPUT);
    }
    bool edge(void) {
        return analogRead(sig.pno) > BLACK;
    }

   private:
    Pin sig;
};

class Bot {
   private:
    enum wheels {
        LF,  // left front
        RF,  // right front
        LB,  // left back
        RB,  // right back
    };
    enum sensors {
        FRONT,
        LEFT,
        RIGHT,
        BACK,
    };

   public:
    Bot(Wheel (&wheel)[4], Infrared (&gnd)[4], Sonar (&opp)[4])
        : wheel(wheel), gnd(gnd), opp(opp) { init(); }
    void init(void) {
        for (int i = 0; i < 4; i++) {
            wheel[i].init();
            gnd[i].init();
            opp[i].init();
        }
    }
    void forward(void) {
        wheel[LF].forward();
        wheel[RF].forward();
        wheel[LB].forward();
        wheel[RB].forward();
    }
    void backward(void) {
        wheel[LF].backward();
        wheel[RF].backward();
        wheel[LB].backward();
        wheel[RB].backward();
    }
    void brake(void) {
        wheel[LF].brake();
        wheel[RF].brake();
        wheel[LB].brake();
        wheel[RB].brake();
    }
    void left(void) {
        wheel[LF].backward();
        wheel[RF].forward();
        wheel[LB].backward();
        wheel[RB].forward();
    }
    void right(void) {
        wheel[LF].forward();
        wheel[RF].backward();
        wheel[LB].forward();
        wheel[RB].backward();
    }
    void write(void) {
        for (int i = 0; i < 4; i++) {
            digitalWrite(wheel[i].in1.pno, wheel[i].in1.val);
            digitalWrite(wheel[i].in2.pno, wheel[i].in2.val);
        }
    }
    bool search(void) {
        for (int i = 0; i < 4; i++)
            if (gnd[i].edge() == true)
                return true;
        return false;
    }
    void dodge(void) {
        if (gnd[FRONT].edge() == true)
            backward();
    }

   private:
    Wheel (&wheel)[4];
    Infrared (&gnd)[4];  // Infrared sensor detects boundary
    Sonar (&opp)[4];     // Sonar detects opponent
};

int main(void) {
    Wheel wheel[4] = {Wheel(PD0, PD1), Wheel(PD2, PD3), Wheel(PD4, PD5), Wheel(PD6, PD7)};
    Infrared gnd[4] = {Infrared(A0), Infrared(A1), Infrared(A2), Infrared(A3)};
    Sonar opp[4] = {Sonar(PD1, PD2), Sonar(PD1, PD2), Sonar(PD3, PD4), Sonar(PD5, PD6)};
    Bot b(wheel, gnd, opp);

    Serial.begin(9600);

    while (1) {
        // Game over
        if (0) break;

        // Check edges
        for (int i = 0; i < 4; i++)
            ;

        // Find opponent
        for (int i = 0; i < 4; i++)
            ;

        // Write-out pins.
        b.write();
        delay(50);
    }

    return EXIT_SUCCESS;
}
