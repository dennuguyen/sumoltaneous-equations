# Software

## Development Environment

### Setup

1. Install Visual Studio 2019
    1. C++ CMake tools for Windows
    2. C++ Clang tools for Windows (10.0.0 - x64/x86)

2. Clone this repository

3. Install any libraries

### Libraries

- OpenCV (Windows): https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html

### Target

This project targets both Windows and Linux.

## Robotic Software Architecture

Inspired by MTRN3500, we reuse the concept of modules:
1. Vision Processing
2. Robot Control

How these modules interact with each other and the world forms the robotic software architecture. We can avoid the use of ROS for layer communication as it is too complicated to setup and we do not need any of its packages. Therefore we develop our own publisher-subscriber service.
