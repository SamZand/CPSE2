#ifndef _LINE_HPP
#define _LINE_HPP

#include "figure.hpp"
#include <SFML/Graphics.hpp>

class Line : public Figure {
private:
  sf::Vector2f lineEnd;
  sf::Vertex mVertices[2];
  bool mSelected;

public:
  Line(sf::Vector2f position, sf::Vector2f lineEnd, sf::Color color);

  sf::FloatRect getBounds() const override { return {position, lineEnd}; };

  void update(sf::RenderWindow &window) override;
  void draw(sf::RenderWindow &window) override;

  bool contain(const sf::Vector2f &p) override;
  bool contain(const sf::Vector2i &p) override;

  void write(std::ofstream &file) const;
};

#endif // _LINE_HPP
