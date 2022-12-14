#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include "figure.hpp"
#include <SFML/Graphics.hpp>

class Circle : public Figure {
private:
  sf::CircleShape mCircle;
  float radius;
  bool mSelected;

public:
  Circle(sf::Vector2f position, float radius, sf::Color color);

  sf::FloatRect getBounds() const override {
    return mCircle.getGlobalBounds();
  };

  void update(sf::RenderWindow &window) override;
  void draw(sf::RenderWindow &window) override;

  bool contain(const sf::Vector2f &p) override;
  bool contain(const sf::Vector2i &p) override;
};

#endif // _CIRCLE_HPP
