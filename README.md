# Sumoltaneous Equations

## Problem Statement

Build a UGV to win the sumobot competition i.e. to win, it must be the last robot to overstep the boundary of the dohyo. It must also adhere to the rules and use the parts provided by UNSW Create.

## Requirements

- Maximise torque output from motors.
- Maximise friction between tyres and dohyo.
- Maximise mass.

## Work Breakdown Structure

```mermaid
graph LR
    Sumobot
    Sumobot --> Platform
    Sumobot --> power[Power Supply]
    Sumobot --> Identification
    Sumobot --> Strategy

    power --> Camera
    power --> ultrasonic[Ultrasonic Sensor]
    power --> Controller
    power --> motors[Wheel Motors]

    Identification --> opp[Opponent Identification]
    Identification --> ring[Ring Identification]

    Strategy --> avoidance[Edge Avoidance]
    Strategy --> push[Push Opponent Strategy]
    Strategy --> random[Random Movement Strategy]

    Platform --> Ramp
    Platform --> Body
    Platform --> Hood
    Platform --> Wheels
    Platform --> wheel_mounts[Wheel Mounts]
    Platform --> motor_mounts[Wheel Motor Mounts]
    Platform --> driver_mounts[Motor Driver Mount]
    Platform --> battery_mount[Battery Mount]
    Platform --> camera_mount[Camera Mount]
    Platform --> ultrasonic_mount[Ultrasonic Sensor Mount]
    Platform --> arduino_mount[Controller Mount]
    Platform --> power_supply[Power Supply Mount]
    Platform --> Wiring
```
