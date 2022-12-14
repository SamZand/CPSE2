#ifndef _WALL_HPP
#define _WALL_HPP

#include "figuur.hpp"
#include <SFML/Graphics.hpp>

class Wall : public Figuur {

public:
  Wall(sf::RectangleShape &shape, sf::Vector2f position, sf::Color color);

  void update(sf::RenderWindow &window) override;
};

#endif // _WALL_HPP