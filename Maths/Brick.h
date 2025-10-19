#pragma once
#include <SFML/Graphics.hpp>
#include <Vec2.h>

class Brick 
{
private:
	sf::RectangleShape shape;
	int health;
	bool destroyed = false;
public:
	Brick(math::Vec2f position, math::Vec2f size, int hp);

	bool hit();
	void updateColor();

	void draw(sf::RenderTarget& target);

	sf::FloatRect getGlobalBounds() const;

	bool isDestroyed() const;
};

