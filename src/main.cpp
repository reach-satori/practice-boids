#include <SFML/Graphics.hpp>
#include "boid.h"
#include <vector>





int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML boids test");
    sf::Clock dClock;
    sf::Time t1, t2;

    //std::vector<Boid*> Boids;
    Boid testboid;
    float dt = 0.01;

    while (window.isOpen())
    {
        t1 = dClock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        testboid.step(dt);
        window.clear();
        window.draw(testboid.shape);
        window.display();

        t2 = dClock.restart();
        dt = (t2 - t1).asSeconds();
    }

    return 0;
}
