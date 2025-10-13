#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* window;
	Player* player;

	float deltaTime;
	sf::Clock clock;

	void initWindow();
	void initPlayer();

public:
	Game();
	~Game();
	void update();
	void updateEntities();

	void draw();
	void drawEntities();

	bool isOpen();
};

