# Sumoltaneous Equations

## Rules

![rules](README/bot-rules.jpg)

## Problem Statement

Build a UGV to win the sumobot competition i.e. to win, it must be the last robot to overstep the boundary of the dohyo. It must also adhere to the rules and use the parts provided by UNSW Create.

## Requirements

- Maximise torque output from motors.
- Maximise friction between tyres and dohyo.
- Maximise mass.
- Max base dimensions is 250 mm x 250 mm.
- Max weight is 1.5 kg.
- Must not use additional motors.
- Must use motors, wheels, and battery provided in the kit.

## Work Breakdown Structure

WBS is extremely detailed because:
- Developing a sumobot already dictates a large number of high level decisions which allows the WBS to be defined at lower levels.
- Large project risk demands specific work packages due to experience level of team, conflicting individual commitments, and short project time frame.

```mermaid
graph LR
    Sumobot
    Sumobot --> Platform
    Sumobot --> Identification
    Sumobot --> Strategy
    Sumobot --> Architecture

    Identification --> opp[Opponent Identification]
    Identification --> ring[Ring Identification]

    Architecture --> Flow
    Flow --> control_loop[Control Loop]

    Architecture --> Abstraction
    Abstraction --> gpio_interface[GPIO Interface]
    Abstraction --> kinematic_abstraction[Kinematic Abstraction]

    Strategy --> avoidance[Edge Avoidance]
    Strategy --> push[Push Opponent Strategy]
    Strategy --> random[Random Movement Strategy]

    Platform --> Chassis
    Chassis --> chassis_mass[Mass Calculation]
    Chassis --> chassis_cad[CAD]
    Chassis --> chassis_mfg[MFG]

    Platform --> Wheels
    Wheels --> wheel_torque[Torque Calculation]
    Wheels --> wheels_cad[CAD]
    Wheels --> wheels_mfg[MFG]

    Platform --> power[Power Supply]
    power --> power_schematic[Power Schematic]
    power --> Wiring[Platform Wiring]
    power --> power_cad[Power Supply CAD]
    power --> mfg_power[MFG]

    Platform --> Electronics
    Electronics --> driver_mounts[Motor Driver]
    Electronics --> battery_mount[Battery]
    Electronics --> camera_mount[Camera]
    Electronics --> ultrasonic_mount[Ultrasonic Sensor]
    Electronics --> arduino_mount[Controller]
```

## Budget



## Resources

- Japanese Sumobots Documentary: https://youtu.be/mS-L2fpV1Is
- Sumobot Strategies: https://youtu.be/rthMiqFCiBA
- SENAI-SC Sumo Robot Example: https://blog.jsumo.com/senai-sc-sumo-robot/.
- Impala Sumo Robot Example: https://blog.jsumo.com/impala-sumo-robot/.
- Arduino Nano Datasheet: https://Datasheet.arduino.cc/hardware/nano
- L298N Motor Controller Datasheet: https://components101.com/sites/default/files/component_datasheet/L298N-Motor-Driver-Datasheet.pdf
- HC-SR04 Ultrasonic Sensor Datasheet: https://www.digikey.com/htmldatasheets/production/1979760/0/0/1/hc-sr04.html
- MH-B IR Sensor Datasheet: https://components101.com/sites/default/files/component_datasheet/Datasheet%20of%20IR%20%20Sensor.pdf
- Turnigy 1250 mAh 3S 30C LiPo Battery: https://hobbyking.com/en_us/turnigy-1250mah-3s-30c-lipo-pack-long.html
- JGA25-370 DC Motor: https://www.aliexpress.com/item/1005001279982165.html