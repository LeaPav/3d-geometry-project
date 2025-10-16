#include "Player.h"

void Player::initPlayer()
{
	shape.setSize(math::Vec2f(100.f, 20.f));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(math::Vec2f(500, 550));
}

Player::Player(float s) : speed(s)
{
	initPlayer();
}

void Player::handleInput(float deltaTime)
{
	math::Vec2f move(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		move.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		move.x -= speed * deltaTime;
	}

	math::Vec2f pos = shape.getPosition();
	math::Vec2f newPos = pos + move;
	shape.setPosition(newPos);
}

void Player::update(float deltaTime)
{
	handleInput(deltaTime);
}

void Player::draw(sf::RenderTarget& target)
{
	target.draw(shape);
}
