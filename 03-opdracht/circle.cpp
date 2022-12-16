#include "circle.hpp"

Circle::Circle(sf::Vector2f position, float radius, sf::Color color)
    : Figure(position, color), radius(radius), mSelected(false) {

  mCircle.setRadius(radius);
  mCircle.setPosition(position);
  mCircle.setFillColor(color);
  mCircle.setOrigin(radius, radius);
}

void Circle::update(sf::RenderWindow &window) { mCircle.setPosition(position); }

void Circle::draw(sf::RenderWindow &window) {
  sf::Color tmp = color;
  if (selected) {
    mCircle.setOutlineColor(selectedColor);
    mCircle.setOutlineThickness(2);
  }
  if (!selected) {
    mCircle.setOutlineThickness(0);
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

void Circle::write(std::ofstream &file) const {
  file << "(" << position.x << ", " << position.y << ") ";
  file << "Circle ";
  file << getColorName(color) << " ";
  file << radius;
}
