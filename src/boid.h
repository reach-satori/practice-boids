#pragma once
#include <SFML/Graphics.hpp>

class Boid {
    public:
        Boid();
        int x = 500, y = 500;
        float velocity = 30.f; //pixels/second?
        float rotVel = 0.f;
        float direction = 180.f ; // angle? actually might be able to put it on the shape directly
        float size = 10.f;

        sf::Color color = sf::Color::Red;
        sf::CircleShape shape;

        void step(float dt);


};
