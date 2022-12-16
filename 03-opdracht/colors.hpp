#ifndef _COLORS_HPP
#define _COLORS_HPP

#include <SFML/Graphics.hpp>

const struct {
  const char *name;
  sf::Color color;

} colors[]{{"black", sf::Color::Black},     {"blue", sf::Color::Blue},
           {"cyan", sf::Color::Cyan},       {"green", sf::Color::Green},
           {"magenta", sf::Color::Magenta}, {"red", sf::Color::Red},
           {"white", sf::Color::White},     {"yellow", sf::Color::Yellow}};

#endif // _COLORS_HPP