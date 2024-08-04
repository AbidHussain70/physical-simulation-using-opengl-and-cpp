#include <GL/glut.h>
#include "pendulum.h"
#include <iostream>
#include <cmath>

// Pendulum initialization
Pendulum pendulum(1.0f, 1.57f, 0.995f, 9.81f); // 1 meter length, 90 degrees initial angle, damping factor, Earth gravity

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // Dark gray background
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D effects
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glEnable(GL_BLEND); // Enable blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending function

    // Lighting setup
    GLfloat light_position[] = { 2.0f, 2.0f, 2.0f, 1.0f };
    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Set light properties
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0); // Enable light 0
}

// Function to draw a gradient background
void drawGradientBackground() {
    // Save the current projection and modelview matrices
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST); // Disable depth testing
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.5f); // Top color
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f); // Bottom color
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
    glEnable(GL_DEPTH_TEST); // Enable depth testing

    // Restore the projection and modelview matrices
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

// Function to draw the pendulum
void drawPendulum() {
    // Debugging: Print coordinates
    std::cout << "Rod: Origin (" << pendulum.originX << ", " << pendulum.originY << "), "
              << "Bob (" << pendulum.bobX << ", " << pendulum.bobY << ")\n";

    // Draw the rod
    glColor3f(1.0f, 1.0f, 1.0f);
    glDisable(GL_LIGHTING); // Disable lighting to make sure the rod is visible
    glBegin(GL_LINES);
    glVertex3f(pendulum.originX, pendulum.originY, 0.0f); // Use 3D coordinates
    glVertex3f(pendulum.bobX, pendulum.bobY, 0.0f); // Use 3D coordinates
    glEnd();
    glEnable(GL_LIGHTING); // Re-enable lighting

    // Draw the bob
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the bob
    glPushMatrix();
    glTranslatef(pendulum.bobX, pendulum.bobY, 0.0f);
    glutSolidSphere(0.05, 50, 50); // Draw a solid sphere as the bob
    glPopMatrix();
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear both color and depth buffers
    glLoadIdentity();

    // Camera setup
    gluLookAt(0.0, 1.5, 3.0, // Eye position
              0.0, 0.0, 0.0, // Look-at position
              0.0, 1.0, 0.0); // Up vector

    drawGradientBackground();
    drawPendulum();

    glutSwapBuffers();
}

// Function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0); // Use perspective projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Function to update the pendulum's state
void update(int value) {
    pendulum.update(0.016f); // Update the pendulum with a time step of 0.016 seconds (60 updates per second)

    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, update, 0); // Call update again after 16 milliseconds
}

// Main function
int main(int argc, char** argv) {
    pendulum.angularVel = 0.5f; // Initial push with angular velocity

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Pendulum Simulation");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
