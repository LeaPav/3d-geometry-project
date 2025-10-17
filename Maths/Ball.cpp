#include "Ball.h"

Ball::Ball(float s, float radius, math::Vec2f pos) : Entity(s, pos)
{
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::White);
	shape.setPosition(pos);
	shape.setOrigin(math::Vec2f(radius, radius));

	velocity = math::Vec2f(-1.f, -1.f).Normalized() * speed;
}

void Ball::handleWallCollision(const sf::RenderWindow& window)
{
	math::Vec2f pos = shape.getPosition();
	float radius = shape.getRadius();

	if (pos.x - radius < 0 || pos.x + radius > window.getSize().x)
		velocity.x *= -1;
	if (pos.y - radius < 0)
		velocity.y *= -1;

}

void Ball::handlePlayerCollision(const Player& player)
{
	math::Vec2f pos = shape.getPosition();
	
	if (shape.getGlobalBounds().findIntersection(player.getGlobalBounds())) {
		velocity.y *= -1;
	}
}

void Ball::update(float deltaTime, const sf::RenderWindow& window) 
{
	math::Vec2f pos = shape.getPosition();
	pos += velocity * deltaTime;
	shape.setPosition(pos);
	handleWallCollision(window);

}

void Ball::draw( sf::RenderTarget& target)
{
	target.draw(shape);
}

sf::FloatRect Ball::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}
