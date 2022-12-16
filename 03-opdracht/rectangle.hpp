#ifndef _Rectangle_HPP
#define _Rectangle_HPP

#include "figure.hpp"
#include <SFML/Graphics.hpp>

class Rectangle : public Figure {
private:
  sf::RectangleShape mRectangle;
  sf::Vector2f size;
  bool mSelected;

public:
  Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);

  sf::FloatRect getBounds() const override {
    return mRectangle.getGlobalBounds();
  };

  void update(sf::RenderWindow &window) override;
  void draw(sf::RenderWindow &window) override;

  bool contain(const sf::Vector2f &p) override;
  bool contain(const sf::Vector2i &p) override;

  void write(std::ofstream &file) const;
};

#endif // _Rectangle_HPP