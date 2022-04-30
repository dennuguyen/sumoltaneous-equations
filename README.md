# Sumoltaneous Equations

## Problem Statement

Build a UGV to win the sumobot competition i.e. to win, it must be the last robot to overstep the boundary of the dohyo. It must also adhere to the rules and use the parts provided by UNSW Create.

## Requirements

- Maximise torque output from motors.
- Maximise friction between tyres and dohyo.
- Maximise mass.

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
    opp --> opp_ipynb[IPYNB Documentation]
    opp --> opp_code_doc[Inline Code Documentation]
    opp --> opp_val[Validation]

    Identification --> ring[Ring Identification]
    ring --> ring_ipynb[IPYNB Documentation]
    ring --> ring_code_doc[Inline Code Documentation]
    ring --> ring_val[Validation]

    Architecture --> control[Control Loop Structure]
    control --> control_code_doc[Inline Code Documentation]

    Architecture --> abstract[Abstractions]
    abstract --> abstract_code_doc[Inline Code Documentation]

    Strategy --> avoidance[Edge Avoidance]
    avoidance --> avoidance_code_doc[Inline Code Documentation]
    avoidance --> avoidance_val[Validation]

    Strategy --> push[Push Opponent Strategy]
    push --> push_code_doc[Inline Code Documentation]
    push --> push_val[Validation]

    Strategy --> random[Random Movement Strategy]
    random --> random_code_doc[Inline Code Documentation]
    random --> random_val[Validation]

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
