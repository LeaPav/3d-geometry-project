#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Vec2.h"


class Ball : public Entity
{
private:
	sf::CircleShape shape;
	math::Vec2f velocity;
public:
	Ball(float s, float radius, math::Vec2f pos);

	void handleWallCollision(const sf::RenderWindow& window);
	void handleEntityCollision(const Entity& entity);

	void update(float deltaTime, const sf::RenderWindow& window) override;
	void draw(sf::RenderTarget& target) override;
};

