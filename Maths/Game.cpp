#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode({ 800,700 }), "Game", sf::Style::Default);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

void Game::initPlayer()
{
	player = new Player(200.f, math::Vec2f(500, 650));
}

void Game::initBall()
{
	ball = new Ball(175.f, 10.f, math::Vec2f(400.f, 300.f));
}

Game::Game()
{
	initWindow();
	initPlayer();
	initBall();
}

Game::~Game()
{
	delete window;
	delete player;
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
}

bool Game::isOpen()
{
	return window->isOpen();
}
