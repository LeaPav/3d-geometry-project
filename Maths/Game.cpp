#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode({ 800,600 }), "Game", sf::Style::Default);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

void Game::update()
{
	deltaTime = clock.restart().asSeconds();

	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window->close();
	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);

	window->display();
}

bool Game::isOpen()
{
	return window->isOpen();
}
