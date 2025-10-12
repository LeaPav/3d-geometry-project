#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode({ 800,600 }), "Game", sf::Style::Default);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

void Game::initPlayer()
{
	player = new Player(200.f);
}

Game::Game()
{
	initWindow();
	initPlayer();
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
	}
	updateEntities();
}

void Game::updateEntities()
{
	player->update(deltaTime);
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
}

bool Game::isOpen()
{
	return window->isOpen();
}
