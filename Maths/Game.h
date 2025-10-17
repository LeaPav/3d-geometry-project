#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

class Game
{
private:
	sf::RenderWindow* window;
	Player* player;
	Ball* ball;
	std::vector<Brick> bricks;

	float deltaTime;
	sf::Clock clock;

	void initWindow();
	void initPlayer();
	void initBall();
	void initBricks();

public:
	Game();
	~Game();
	void update();
	void updateEntities();

	void draw();
	void drawEntities();

	bool isOpen();
};

