# Physical Simulation Using OpenGL and C++

This repository contains various physical simulations implemented using OpenGL and C++. Each simulation is organized in its own subdirectory.

## Simple Pendulum

### Description
A simple pendulum simulation demonstrating the basic principles of pendulum motion using OpenGL for rendering.

### How to Build and Run

1. Navigate to the `simple-pendulum` directory.
2. Build the project using CMake:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```
3. Run the simulation:
    ```sh
    ./PendulumSimulation
    ```

### Files
- `main.cpp`: Contains the main function and OpenGL setup.
- `pendulum.h`: Header file defining the `Pendulum` class.
- `pendulum.cpp`: Implementation of the `Pendulum` class.

### Requirements
- OpenGL
- GLUT
- CMake
- A C++ compiler

### Author
- Abid Hussain
