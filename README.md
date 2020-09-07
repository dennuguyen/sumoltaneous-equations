# Sumobot Competition

![logo](https://i.pinimg.com/originals/6f/ca/06/6fca06664a45c2c4dd6720f6590c7dc7.png)

### Rules
1. Under 1 kg
2. Fit within 200 x 200 mm base
3. Autonomous
4. Powered by battery provided
5. Use Arduino Nano provided
6. No intentional destruction of other bots
7. Bot must be capable of movement
8. No parts that may damage the arena
9. Bot must be stationary for 3 seconds at start of match
10. Must have completed shop tools

### Problem Definition

Build a robot to win the sumobot competition i.e. to win, it must be the last robot to overstep the boundary of the dohyo. It must also adhere to the rules and use the parts provided by UNSW Create.

| **Requirements** | **Constraints** | **Free Variables** |
| --- | --- | --- |
| Provide structure | Maximum base dimension is 200 x 200 mm | Centre of mass |
| Protect against shock impacts | Maximum weight is 1 kg | Chassis material |
| High torque to push opponents| | High speed to outmanoeuvre opponents |

### Fundamental Steps

An overview of the design process with what is considered fundamental steps in order to build a working sumobot.

0. **Plan the project.**
    1. Understand the rules.
    2. Have a problem definition (every good engineer has one before they go solving problems).
1. **Design the chassis.**
    1. The chassis needs to: be heavy to resist being pushed around, have low centre of mass for stability, protect electronics from large impulses, and easily push other bots.
    2. Taking advantage of 3D-printing as our existing manufacturing method, we can print a shell with compartments which we will house our electronics and motors. We don't want to be wasteful with plastic so to increase the mass, we can have "ballast" slots where we can insert metals.
    3. The wheels will be encaged with the chassis to avoid wheel entanglement and damage. The chassis and wheel height difference is also minimal to lower the centre of mass. The wheels will also be in skid-steer format for simplicity of the project and increased reliability from less moving parts.
    4. To easily push other bots around, we will have a scoop which would lift other bots to decrease their stability. The scoop is metal to achieve thinness and maintain rigidity.
2. **Get motor/wheel requirements.**
    1. Obtaining the specification for the motor and wheel happens in tandem. The competition provides __ V, __ A motors. We can perform calculations between the motor specification, desired sumobot velocity and torque, and wheel specification.
    2. Our wheels have three possible states: forward, backward, and brake. To increase simplicity of the project, our sumobot can have three velocities: zero, positive max, and negative max velocity.
3. **Get microcontroller requirements.**
    1. The competition provides an Arduino Nano which has AVR architecture, 16 MHz clock speed, 8 analog pins, 22 digital pins. It has a power consumption of 19 mA, size of 18 x 45 mm, mass of 7 g, max 40 mA DC current on I/O pins.
    2. The microcontroller will influence how we code our project.
4. **Build motor driver.**
    1. From the motor and microcontroller requirements, we have the specifications to build our motor driver.
5. **Code microcontroller and motor driver interaction.**
    1. We have three structs: Bot, Wheel, Pin. Bot has four Wheels, and each Wheel has two digital Pins (to encode the three states). Bot has five states: forward, backward, brake, left, and right.
6. **Code microcontroller and camera interaction.**
    1. We require the camera to tell the bot where the edge of the dohyo is as to not step out and be eliminated.
7. **Code sumobot behaviour.**
    1. 1