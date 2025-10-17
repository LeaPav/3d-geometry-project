#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Entity.h"
class Player : public Entity
{
private:

	sf::RectangleShape shape;

	void initPlayer();

public:
	Player(float s, math::Vec2f pos);

	void handleInput(float deltaTime);
	void handleScreenCollisions(const sf::RenderWindow& window);


	void update(float deltaTime, const sf::RenderWindow& window) override;
	void draw(sf::RenderTarget& target) override;


	math::Vec2f getPosition() const;

	sf::FloatRect getGlobalBounds() const override;
};

