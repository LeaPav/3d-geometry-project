#pragma once
#include "SFML/Graphics.hpp"

class Game
{
private:
	sf::RenderWindow* window;

	float deltaTime;
	sf::Clock clock;

	void initWindow();

public:
	Game();
	~Game();
	void update();
	void draw();

	bool isOpen();
};

