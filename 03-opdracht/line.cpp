#include "line.hpp"

Line::Line(sf::Vector2f position, sf::Vector2f lineEnd, sf::Color color)
    : Figure(position, color), lineEnd(lineEnd), mSelected(false) {
  mVertices[0].position = position;
  mVertices[1].position = lineEnd;
  mVertices[0].color = color;
  mVertices[1].color = color;
}

void Line::draw(sf::RenderWindow &window) {
  if (selected) {
    sf::Color tmp = color;
    mVertices[0].color = selectedColor;
    mVertices[1].color = selectedColor;
    window.draw(mVertices, 2, sf::Lines);
    mVertices[0].color = tmp;
    mVertices[1].color = tmp;
  } else {
    window.draw(mVertices, 2, sf::Lines);
  }
}

void Line::update(sf::RenderWindow &window) {
  mVertices[0].position = position;
  mVertices[1].position = lineEnd;
}

bool Line::contain(const sf::Vector2f &p) {
  sf::FloatRect hitbox = getBounds();
  return hitbox.contains(p.x, p.y);
}

bool Line::contain(const sf::Vector2i &p) {
  sf::FloatRect hitbox = getBounds();
  sf::Vector2f r = {static_cast<float>(p.x), static_cast<float>(p.y)};
  return hitbox.contains(r.x, r.y);
}

void Line::write(std::ofstream &file) const {
  file << "(";
  file << mVertices[0].position.x << ", ";
  file << mVertices[0].position.y << ")";
  file << " Line ";
  file << getColorName(color) << " (";
  file << mVertices[1].position.x << ", ";
  file << mVertices[1].position.y << ")";
}