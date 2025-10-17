#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Entity.h"
class Player
{
private:

	sf::RectangleShape shape;
	math::Vec2f position;
	float speed;

	void initPlayer();

public:
	Player(float s);

	void handleInput(float deltaTime);
	void handleScreenCollisions(const sf::RenderWindow& window);


	void update(float deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderTarget& target);


	math::Vec2f GetPosition() const;
};

