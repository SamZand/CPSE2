#ifndef _FIGUREFACTORY_HPP
#define _FIGUREFACTORY_HPP

#include "circle.hpp"
#include "figure.hpp"
#include <iostream>

std::unique_ptr<Figure> createScreenObject(std::string type, sf::Vector2f pos,
                                                   sf::Color color);

#endif // _FIGUREFACTORY_HPP