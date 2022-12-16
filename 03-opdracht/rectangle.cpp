#include "Rectangle.hpp"

Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : Figure(position, color), size(size), mSelected(false) {
  mRectangle.setSize(size);
  mRectangle.setPosition(position);
  mRectangle.setFillColor(color);
  mRectangle.setOrigin(size.x / 2, size.y / 2);
}

void Rectangle::update(sf::RenderWindow &window) {
  mRectangle.setPosition(position);
}

void Rectangle::draw(sf::RenderWindow &window) {
  sf::Color tmp = color;
  if (selected) {
    mRectangle.setOutlineColor(selectedColor);
    mRectangle.setOutlineThickness(2);
  }
  if (!selected) {
    mRectangle.setOutlineThickness(0);
  }
  window.draw(mRectangle);
  if (mRectangle.getFillColor() != tmp) {
    mRectangle.setFillColor(tmp);
  }
}

bool Rectangle::contain(const sf::Vector2f &p) {
  sf::FloatRect hitbox = getBounds();
  return hitbox.contains(p.x, p.y);
}

bool Rectangle::contain(const sf::Vector2i &p) {
  sf::FloatRect hitbox = getBounds();
  sf::Vector2f r = {static_cast<float>(p.x), static_cast<float>(p.y)};
  return hitbox.contains(r.x, r.y);
}

void Rectangle::write(std::ofstream &file) const {
  file << "(" << position.x << ", " << position.y << ") ";
  file << "Rectangle ";
  file << getColorName(color) << " ";
  file << "(" << size.x << ", " << size.y << ")";
}