#include "figuur.hpp"

Figuur::Figuur(sf::Shape &shape, sf::Vector2f position, sf::Color color)
    : shape(shape), position(position), color(color) {
  shape.setFillColor(color);
  shape.setPosition(position);
}

void Figuur::draw(sf::RenderWindow &window) const { window.draw(shape); }

void Figuur::move(sf::Vector2f delta) { position += delta; }

void Figuur::jump(sf::Vector2f target) { position = target; }

void Figuur::jump(sf::Vector2i target) {
  jump(
      sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
}

bool Figuur::overlaps(const Figuur &other) {
  return shape.getGlobalBounds().intersects(other.shape.getGlobalBounds());
};