#include "Brick.h"

Brick::Brick(math::Vec2f position, math::Vec2f size, int hp) : health(hp)
{
	shape.setSize(size);
	shape.setPosition(position);
	updateColor();
}

void Brick::hit()
{
	if (destroyed) return;
	health--;
	if (health <= 0) {
		destroyed = true;
	}
	else {
		updateColor();
	}
}

void Brick::updateColor()
{
	switch (health) {
	case 3: shape.setFillColor(sf::Color::Blue); break;
	case 2: shape.setFillColor(sf::Color::Yellow); break;
	case 1: shape.setFillColor(sf::Color::Red); break;
	default: shape.setFillColor(sf::Color::Transparent); break;

	}
}

void Brick::draw(sf::RenderTarget& target)
{
	if(!destroyed)
		target.draw(shape);
}

sf::FloatRect Brick::getGlobalBounds() const 
{
	return shape.getGlobalBounds();
}

bool Brick::isDestroyed() const
{
	return destroyed;
}
