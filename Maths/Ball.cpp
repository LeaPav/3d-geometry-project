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

		float playerCenterX = player.getGlobalBounds().position.x + player.getGlobalBounds().size.x / 2.f;
		float ballX = shape.getPosition().x;
		float offset = (ballX - playerCenterX) / (player.getGlobalBounds().size.x / 2.f);

		velocity.y = -std::abs(velocity.y);
		velocity.x += offset * speed;
		velocity = velocity.Normalized() * speed;
	}
}

void Ball::handleBrickCollision(std::vector<Brick>& bricks)
{
	for (Brick& brick : bricks) {
		if (!brick.isDestroyed() && shape.getGlobalBounds().findIntersection(brick.getGlobalBounds())) {
			brick.hit();
			velocity.y *= -1;
		}
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
