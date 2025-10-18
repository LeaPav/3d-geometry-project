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

	if (pos.x - radius < 0) {
		pos.x = radius;
		velocity = math::Vec2f::Reflect(velocity, math::Vec2f::Right());
	}
	else if (pos.x + radius > window.getSize().x) {
		pos.x = window.getSize().x - radius;
		velocity = math::Vec2f::Reflect(velocity, math::Vec2f::Left());
	}
	if (pos.y - radius < 0) {
		pos.y = radius;
		velocity = math::Vec2f::Reflect(velocity, math::Vec2f::Down());
	}
	shape.setPosition(pos);

}

void Ball::handlePlayerCollision(const Player& player)
{
	math::Vec2f pos = shape.getPosition();
	
	if (const std::optional intersection = shape.getGlobalBounds().findIntersection(player.getGlobalBounds())) {

		float playerCenterX = player.getGlobalBounds().position.x + player.getGlobalBounds().size.x / 2.f;
		float ballX = shape.getPosition().x;
		float offset = (ballX - playerCenterX) / (player.getGlobalBounds().size.x / 2.f);
		offset = std::fmax(-0.8f, std::fmin(0.8f, offset));

		velocity = math::Vec2f::Reflect(velocity, math::Vec2f(0.f, -1.f));
		velocity.x += offset * speed;
		velocity.y = -std::abs(velocity.y);
		velocity = velocity.Normalized() * speed;
	}
}

int Ball::handleBrickCollision(std::vector<Brick>& bricks)
{
	sf::FloatRect intersection;
	for (Brick& brick : bricks) {

		if(brick.isDestroyed()) continue;

		if (const std::optional intersection = shape.getGlobalBounds().findIntersection(brick.getGlobalBounds())) {
			brick.hit();
			if (intersection->size.x < intersection->size.y) {
				//velocity.x *= -1;
				math::Vec2f normal = (velocity.x > 0) ? math::Vec2f::Left() : math::Vec2f::Right();
				velocity = math::Vec2f::Reflect(velocity, normal);
			}
			else {
				math::Vec2f normal = (velocity.y > 0) ? math::Vec2f::Up() : math::Vec2f::Down();
				velocity = math::Vec2f::Reflect(velocity, normal);
			}
			return 1;
			
		}
	}
	return 0;
}

void Ball::update(float deltaTime, const sf::RenderWindow& window) 
{
	
	math::Vec2f pos = shape.getPosition();
	pos += velocity * deltaTime;
	shape.setPosition(pos);


}

void Ball::draw( sf::RenderTarget& target)
{
	target.draw(shape);
}

void Ball::reset(math::Vec2f pos)
{
	shape.setPosition(pos);
	velocity = math::Vec2f(-1.f, -1.f).Normalized() * speed;
}

sf::FloatRect Ball::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

math::Vec2f Ball::getPosition() const 
{
	return shape.getPosition();
}
