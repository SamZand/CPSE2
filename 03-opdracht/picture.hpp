#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include "figure.hpp"

class Picture : public Figure {
private:
  sf::Texture texture;
  sf::Sprite sprite;
  std::string filename;
  bool mSelected;

public:
  Picture(sf::Vector2f position, const std::string &filename);

  sf::FloatRect getBounds() const override {
    return sf::FloatRect{position,
                         sf::Vector2f(static_cast<float>(texture.getSize().x),
                                      static_cast<float>(texture.getSize().y))};
  };

  void update(sf::RenderWindow &window) override;
  void draw(sf::RenderWindow &window) override;

  bool contain(const sf::Vector2f &p) override;
  bool contain(const sf::Vector2i &p) override;
  void write(std::ofstream &file) const;
};

#endif // _PICTURE_HPP
