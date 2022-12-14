#include "wall.hpp"

Wall::Wall(sf::RectangleShape &shape, sf::Vector2f position, sf::Color color)
    : Figuur(shape, position, color) {}

void Wall::update(sf::RenderWindow &window) { shape.setPosition(position); }