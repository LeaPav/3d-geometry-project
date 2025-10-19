#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode({ 800,700 }), "Breakout", sf::Style::Default);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

void Game::initFont()
{
	if (!font.openFromFile("assets/Font/game_over.ttf")) {
		throw std::runtime_error("Errorloading font.");
	}
	text = new sf::Text(font);
	text->setFont(font);
	text->setCharacterSize(60);
	text->setFillColor(sf::Color::White);
	text->setPosition(math::Vec2f(0.f, -20.f));
}

void Game::initPlayer()
{
	player = new Player(300.f, math::Vec2f(500, 650));
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

Game::Game() : lives(3)
{
	initWindow();
	initFont();
	initPlayer();
	initBall();
	initBricks();
}

Game::~Game()
{
	delete window;
	delete player;
	delete ball;
	delete text;
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

	if (lives <= 0) {
		window->close();
	}
}

void Game::updateEntities()
{
	int subSteps = 4;
	float deltaStep = deltaTime / static_cast<float>(subSteps);

	for (int i = 0; i < subSteps; i++) {
		ball->update(deltaStep, *window);

		ball->handlePlayerCollision(*player);
		ball->handleWallCollision(*window);
	
		score += ball->handleBrickCollision(bricks) * 25;

		checkBallLost();
		if (ballLost) {
			ball->reset(math::Vec2f(400.f, 300.f));
			ballLost = false;
			break;
		}
	}

	player->update(deltaTime, *window);

}

void Game::checkBallLost()
{
	if (ball->getPosition().y - ball->getRadius() > window->getSize().y) {
		lives--;
		ballLost = true;
	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);
	drawEntities();
	drawHUD();
	window->display();
}

void Game::drawHUD()
{
	text->setString("Score: " + std::to_string(score) + " Lives: " + std::to_string(lives));
	window->draw(*text);
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
