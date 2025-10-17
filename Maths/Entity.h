#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"

class Entity
{
protected:
	float speed;
	math::Vec2f position;
public:
	Entity(float s, math::Vec2f pos);
	virtual void update(float deltaTime, const sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderTarget& target) = 0;

};

