#include "picture.hpp"

Picture::Picture(sf::Vector2f position, const std::string &filename)
    : Figure{position, sf::Color::Black}, filename{filename}, mSelected{false} {

  if (!texture.loadFromFile(filename)) {
    throw invalidFile(filename);
  }
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Picture::update(sf::RenderWindow &window) { sprite.setPosition(position); }

void Picture::draw(sf::RenderWindow &window) { window.draw(sprite); }

bool Picture::contain(const sf::Vector2f &p) {
  return sprite.getGlobalBounds().contains(p.x, p.y);
}

bool Picture::contain(const sf::Vector2i &p) {
  sf::Vector2f r = {static_cast<float>(p.x), static_cast<float>(p.y)};
  return sprite.getGlobalBounds().contains(r.x, r.y);
}

void Picture::write(std::ofstream &file) const {
  file << "(" << position.x << ", " << position.y << ") ";
  file << "Picture ";
  file << filename;
}
