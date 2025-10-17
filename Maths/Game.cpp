#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode({ 800,700 }), "Game", sf::Style::Default);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

void Game::initPlayer()
{
	player = new Player(250.f, math::Vec2f(500, 650));
}

void Game::initBall()
{
	ball = new Ball(400.f, 10.f, math::Vec2f(400.f, 300.f));
}

void Game::initBricks()
{
	bricks.clear();
	int rows[] = { 3, 2, 2, 1 };

	for (int row = 0; row < 4; row++) {
		int hp = rows[row];
		for (int col = 0; col < 12; col++) {
			math::Vec2f size(62.f, 20.f);
			math::Vec2f pos(col * (62.f + 5.f), row *(30.f  + 5.f) + 50.f);
			bricks.emplace_back(pos, size, hp);
		}
	}
}

Game::Game()
{
	initWindow();
	initPlayer();
	initBall();
	initBricks();
}

Game::~Game()
{
	delete window;
	delete player;
	delete ball;
}


void Game::update()
{
	deltaTime = clock.restart().asSeconds();

	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window->close();
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				window->close();
		}
	}
	updateEntities();
}

void Game::updateEntities()
{
	player->update(deltaTime, *window);
	ball->update(deltaTime, *window);
	ball->handlePlayerCollision(*player);
	ball->handleBrickCollision(bricks);
}

void Game::draw()
{
	window->clear(sf::Color::Black);
	drawEntities();
	window->display();
}

void Game::drawEntities()
{
	player->draw(*window);
	ball->draw(*window);
	for (Brick& brick : bricks) {
		brick.draw(*window);
	}
}

bool Game::isOpen()
{
	return window->isOpen();
}
