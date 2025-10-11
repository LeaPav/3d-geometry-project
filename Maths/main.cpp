#include <iostream>
#include "SFML/Graphics.hpp"
#include "Vec2.h"
#include "Vec3.h"

int main()
{
    
   

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(math::Vec2f(100, 200));


    float deltaTime;
    sf::Clock clock;

    while (window.isOpen())
    {

        deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        math::Vec2f move(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            move.x += 200 * deltaTime;
        }
        shape.move(move);

        window.clear();
        window.draw(shape);
        window.display();
    }

}


