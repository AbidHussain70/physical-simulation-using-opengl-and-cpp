#include "pendulum.h"
#include <cmath> // For sin and cos functions

// Constructor to initialize the pendulum
Pendulum::Pendulum(float length, float angle, float damping, float gravity)
    : length(length), angle(angle), angularVel(0.0), angularAcc(0.0), damping(damping), gravity(gravity) {
    originX = 0.0;
    originY = 0.0;
    calculateBobPosition();
}

// Function to update the state of the pendulum
void Pendulum::update(float dt) {
    // Calculate angular acceleration (α = -g / L * sin(θ))
    angularAcc = (-gravity / length) * sin(angle);

    // Update angular velocity (ω = ω + α * dt)
    angularVel += angularAcc * dt;

    // Apply damping to simulate energy loss
    angularVel *= damping;

    // Update angle (θ = θ + ω * dt)
    angle += angularVel * dt;

    // Update bob position based on the new angle
    calculateBobPosition();
}

// Function to calculate the bob's position based on the current angle
void Pendulum::calculateBobPosition() {
    // Calculate bob position in Cartesian coordinates
    // bobX = originX + L * sin(θ)
    // bobY = originY - L * cos(θ)
    bobX = originX + length * sin(angle);
    bobY = originY - length * cos(angle);
}
