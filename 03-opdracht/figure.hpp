#ifndef _FIGURE_HPP
#define _FIGURE_HPP

#include "colors.hpp"
#include "exception.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Figure {

protected:
  sf::Vector2f position;
  sf::Color color;
  sf::Color selectedColor;
  virtual std::string getColorName(sf::Color color) const;

public:
  bool selected = false;
  Figure(sf::Vector2f position, sf::Color color);

  virtual void draw(sf::RenderWindow &window) = 0;
  virtual void update(sf::RenderWindow &window) = 0;

  virtual void move(sf::Vector2f delta);
  virtual void jump(sf::Vector2f target);
  virtual void jump(sf::Vector2i target);

  virtual sf::FloatRect getBounds() const = 0;

  virtual bool contain(const sf::Vector2f &p) = 0;
  virtual bool contain(const sf::Vector2i &p) = 0;

  virtual void write(std::ofstream &output) const = 0;
};
#endif // FIGURE_hpp