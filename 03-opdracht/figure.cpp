#include "figure.hpp"

Figure::Figure(sf::Vector2f position, sf::Color color)
    : position(position), color(color), selectedColor(sf::Color(0, 255, 0)) {}

void Figure::move(sf::Vector2f delta) { position += delta; }

void Figure::jump(sf::Vector2f target) { position = target; }

void Figure::jump(sf::Vector2i target) {
  jump(
      sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
}

bool Figure::contain(const sf::Vector2f &p) {
  sf::FloatRect hitbox = getBounds();
  return hitbox.contains(p.x, p.y);
}
bool Figure::contain(const sf::Vector2i &p) {
  sf::FloatRect hitbox = getBounds();
  sf::Vector2f r = {static_cast<float>(p.x), static_cast<float>(p.y)};
  return hitbox.contains(r.x, r.y);
}