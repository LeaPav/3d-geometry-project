#include "Player.h"
#include "Ball.h"

void Player::initPlayer()
{
	shape.setSize(math::Vec2f(100.f, 20.f));
	shape.setFillColor(sf::Color::Blue);
	
}

Player::Player(float s, math::Vec2f pos) : Entity(s, pos)
{
	initPlayer();
	shape.setPosition(position);
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

void Player::handleScreenCollisions(const sf::RenderWindow& window)
{
	sf::FloatRect bounds = shape.getGlobalBounds();
	if (bounds.position.x < 0) {
		
		shape.setPosition(math::Vec2f(0, bounds.position.y));
	}
	if (bounds.position.x + bounds.size.x > window.getSize().x) {
		shape.setPosition(math::Vec2f(window.getSize().x - bounds.size.x, bounds.position.y));
	}
}



void Player::update(float deltaTime, const sf::RenderWindow& window)
{
	handleInput(deltaTime);
	handleScreenCollisions(window);
}

void Player::draw(sf::RenderTarget& target)
{
	target.draw(shape);
}

math::Vec2f Player::getPosition() const {
	return position;
}

float Ball::getRadius() const
{
	return shape.getRadius();
}

sf::FloatRect Player::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}
