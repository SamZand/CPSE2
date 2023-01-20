#include <functional>
#include <iostream>
#include <memory>
#include <sfml/Graphics.hpp>
#include <vector>

#include "action.hpp"
#include "ball.hpp"
#include "figuur.hpp"
#include "wall.hpp"

unsigned const int windowWidth = 1920;
unsigned const int windowHeight = 1080;

int main(int argc, char *argv[]) {
   std::cout << "Start opdracht 1 \n";

   sf::RenderWindow window{sf::VideoMode{windowWidth, windowHeight},
                           "SFML window"};
   window.setFramerateLimit(60);

   const float wallSize = 30;
   const float blockSize = 200;
   const float wallX = window.getSize().x;
   const float wallY = window.getSize().y;

   sf::CircleShape ballShape1{30};
   sf::CircleShape ballShape2{40};

   sf::RectangleShape upperWallShape{sf::Vector2f{wallX, wallSize}};
   sf::RectangleShape lowerWallShape{sf::Vector2f{wallX, wallSize}};
   sf::RectangleShape rightWallShape{sf::Vector2f{wallSize, wallY}};
   sf::RectangleShape leftWallShape{sf::Vector2f{wallSize, wallY}};
   sf::RectangleShape blokShape{sf::Vector2f{blockSize, blockSize}};

   std::vector<std::unique_ptr<Figuur>> figuren;
   figuren.reserve(10);
   figuren.emplace_back(
       new Wall(blokShape, sf::Vector2f(400, 400), sf::Color::Red));
   figuren.emplace_back(new Ball(ballShape1, sf::Vector2f(wallX / 2, wallY / 2),
                                 sf::Color::Green));
   figuren.emplace_back(
       new Ball(ballShape2, sf::Vector2f(100, 100), sf::Color::Blue));
   figuren.emplace_back(
       new Wall(upperWallShape, sf::Vector2f(0, 0), sf::Color::Yellow));
   figuren.emplace_back(new Wall(
       lowerWallShape, sf::Vector2f(0.0, wallY - wallSize), sf::Color::Magenta));
   figuren.emplace_back(
       new Wall(leftWallShape, sf::Vector2f(0.0, 0.0), sf::Color::Cyan));
   figuren.emplace_back(new Wall(
       rightWallShape, sf::Vector2f(wallX - wallSize, 0.0), sf::Color::White));

   action actions[] =
       {action(sf::Keyboard::Left,
               [&]() { figuren[0]->move(sf::Vector2f(-1.0, 0.0)); }),
        action(sf::Keyboard::Right,
               [&]() { figuren[0]->move(sf::Vector2f(+1.0, 0.0)); }),
        action(sf::Keyboard::Up,
               [&]() { figuren[0]->move(sf::Vector2f(0.0, -1.0)); }),
        action(sf::Keyboard::Down,
               [&]() { figuren[0]->move(sf::Vector2f(0.0, +1.0)); }),
        action(sf::Mouse::Left,
               [&]() { figuren[0]->jump(sf::Mouse::getPosition(window)); })},
          action(sf::Keyboard::Escape, [&]() { window.close(); });

   while (window.isOpen()) {
      for (auto &action : actions) {
         action();
      }

      window.clear();
      for (auto &entity : figuren) {
         entity->update(window);
         entity->draw(window);

         for (auto &other : figuren) {
            if (entity != other) {
               entity->interact(*other);
            }
         }
      }
      window.display();

      sf::sleep(sf::milliseconds(20));

      sf::Event event;
      while (window.pollEvent(event)) {
         if (event.type == sf::Event::Closed) {
            window.close();
         }
      }
   }

   std::cout << "Terminating application\n";
   return 0;
}
