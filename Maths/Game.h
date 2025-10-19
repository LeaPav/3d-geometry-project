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

	int score;
	int lives;
	bool ballLost = false;

	sf::Font font;
	sf::Text* text;
	sf::Text* livestext;

	void initWindow();
	void initFont();
	void initPlayer();
	void initBall();
	void initBricks();

public:
	Game();
	~Game();
	void update();
	void updateEntities();
	void checkBallLost();

	void draw();
	void drawHUD();
	void drawEntities();

	bool isOpen();
};

