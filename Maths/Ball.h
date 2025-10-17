#pragma once
#include "Entity.h"
#include "Player.h"
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
	void handlePlayerCollision(const Player& player);

	void update(float deltaTime, const sf::RenderWindow& window) override;
	void draw(sf::RenderTarget& target) override;

	sf::FloatRect getGlobalBounds() const override;
};

