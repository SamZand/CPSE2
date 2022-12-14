#include "circle.hpp"

Circle::Circle(sf::Vector2f position, float radius, sf::Color color)
    : Figure(position, color), radius(radius), mSelected(false) {

  mCircle.setRadius(radius);
  mCircle.setPosition(position);
  mCircle.setFillColor(color);
}

void Circle::update(sf::RenderWindow &window) { mCircle.setPosition(position); }

void Circle::draw(sf::RenderWindow &window) {
  sf::Color tmp = color;
  if (selected) {
    mCircle.setOutlineColor(selectedColor);
    mCircle.setOutlineThickness(2);
  }
  window.draw(mCircle);
  if (mCircle.getFillColor() != tmp) {
    mCircle.setFillColor(tmp);
  }
}

bool Circle::contain(const sf::Vector2f &p) {
  sf::FloatRect hitbox = getBounds();
  return hitbox.contains(p.x, p.y);
}

bool Circle::contain(const sf::Vector2i &p) {
  sf::FloatRect hitbox = getBounds();
  sf::Vector2f r = {static_cast<float>(p.x), static_cast<float>(p.y)};
  return hitbox.contains(r.x, r.y);
}
