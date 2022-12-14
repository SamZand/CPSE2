#ifndef _FIGUUR_HPP
#define _FIGUUR_HPP

#include <SFML/Graphics.hpp>

class Figuur {

protected:
  sf::Shape &shape;
  sf::Vector2f position;
  sf::Color color;

public:
  Figuur(sf::Shape &shape, sf::Vector2f position, sf::Color color);

  virtual void draw(sf::RenderWindow &window) const;
  virtual void update(sf::RenderWindow &window) = 0;

  virtual void move(sf::Vector2f delta);
  virtual void jump(sf::Vector2f target);
  virtual void jump(sf::Vector2i target);

  virtual void interact(const Figuur &other){};

protected:
  bool overlaps(const Figuur &other);
};
#endif // FIGUUR_hpp