#include "Player.h"
#include "Ball.h"

void Player::initPlayer()
{
	shape.setSize(math::Vec2f(120.f, 10.f));
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		move.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		move.x -= speed * deltaTime;
	}

	math::Vec2f pos = shape.getPosition();
	math::Vec2f newPos = pos + move;
	shape.setPosition(newPos);
}

void Player::handleScreenCollisions(const sf::RenderWindow& window)
{
	sf::FloatRect bounds = shape.getGlobalBounds();

	math::Vec2f pos = math::Vec2f(bounds.position.x, bounds.position.y);
	math::Vec2f size = math::Vec2f(bounds.size.x, bounds.size.y);
	if (pos.x < 0) {
		
		shape.setPosition(math::Vec2f(0, pos.y));
	}
	if (pos.x + size.x > window.getSize().x) {
		shape.setPosition(math::Vec2f(window.getSize().x - size.x, pos.y));
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
	return shape.getPosition();
}

float Ball::getRadius() const
{
	return shape.getRadius();
}

sf::FloatRect Player::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}
