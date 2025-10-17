#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Ball.h"

class Game
{
private:
	sf::RenderWindow* window;
	Player* player;
	Ball* ball;

	float deltaTime;
	sf::Clock clock;

	void initWindow();
	void initPlayer();
	void initBall();

public:
	Game();
	~Game();
	void update();
	void updateEntities();

	void draw();
	void drawEntities();

	bool isOpen();
};

