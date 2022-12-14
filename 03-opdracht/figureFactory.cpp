#include "figureFactory.hpp"

std::unique_ptr<Figure> createScreenObject(std::string type, sf::Vector2f pos,
                                           sf::Color color) {
  if (type == "circle") {
    float diameter = 30.0f;
    return std::make_unique<Circle>(pos, diameter, color);
    // } else if (type == "rectangle") {
    //   sf::Vector2f end;
    //   std::cout << "Enter the end point of the rectangle: ";
    //   std::cin >> end.x >> end.y;
    //   return std::make_unique<Rectangle>(pos, color, end);
  } else {
    return nullptr;
  }
}
