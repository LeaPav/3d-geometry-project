#pragma once
#include "SFML/Graphics.hpp"
#include "Vec2.h"
class Player
{
private:

	sf::RectangleShape shape;
	float speed;

	void initPlayer();

public:
	Player(float s);

	void handleInput(float deltaTime);

	void update(float deltaTime);
	void draw(sf::RenderTarget& target);


};

