#ifndef _BALL_HPP
#define _BALL_HPP

#include "figuur.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Ball : public Figuur {
private:
  static const uint8_t speed = 6;
  sf::Vector2f velocity{};

public:
  Ball(sf::CircleShape &shape, sf::Vector2f position, sf::Color color);

  void update(sf::RenderWindow &window) override;
  void interact(const Figuur &other) override;
};

#endif
