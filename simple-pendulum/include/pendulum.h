#ifndef PENDULUM_H
#define PENDULUM_H

class Pendulum {
public:
    float angle;        // Current angle (radians)
    float angularVel;   // Angular velocity
    float angularAcc;   // Angular acceleration
    float length;       // Length of the rod (meters)
    float originX, originY; // Origin coordinates
    float bobX, bobY;   // Bob coordinates
    float damping;      // Damping factor
    float gravity;      // Gravity

    Pendulum(float length, float angle, float damping = 0.99f, float gravity = 9.81f);

    void update(float dt);
    void calculateBobPosition();
};

#endif // PENDULUM_H
