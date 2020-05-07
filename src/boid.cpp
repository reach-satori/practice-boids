#include "boid.h"
#include <math.h>
#include <stdio.h>
#define PI 3.14159265

Boid::Boid(void) {
    shape = sf::CircleShape(size, 3);
    shape.setPosition(x, y);
    shape.setFillColor(color);
    shape.setRotation(direction);
}

void Boid::step(float dt) {
    float dy = -cos(direction*PI/180) * velocity*dt;
    float dx = sin(direction*PI/180) * velocity*dt;
    shape.move(dx, dy);

    direction += 30.f*dt;
    if (direction > 360.f) {
        direction -= 360.f;
    }
    if (direction < 0.f) {
        direction += 360.f;
    }
    shape.setRotation(direction);

}


