#include "ball.hpp"
#include "iostream"
#include <math.h>
#define PI 3.1415926535897932384626

Ball::Ball(sf::CircleShape &shape, sf::Vector2f position, sf::Color color)
    : Figuur(shape, position, color), velocity(speed, speed) {}

void Ball::update(sf::RenderWindow &window) {
  move(velocity);
  shape.setPosition(position);
}

void Ball::interact(const Figuur &other) {
  if (overlaps(other)) {
    float angle = atan2f(velocity.y, velocity.x) - PI / 2;

    velocity.x = cos(angle) * speed;
    velocity.y = sin(angle) * speed;
    velocity.x < 1 ? velocity.x = 6 : velocity.x = -6;
    velocity.y < 1 ? velocity.y = 6 : velocity.y = -6;
    move(velocity);
  }
}