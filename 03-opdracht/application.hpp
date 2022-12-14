#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>

#include "action.hpp"
#include "circle.hpp"
#include "figure.hpp"
#include "figureFactory.hpp"

#include <iostream>
#include <memory>
#include <vector>

class Application {
public:
  Application();
  void run();
  unsigned const int windowWidth = 720;
  unsigned const int windowHeight = 480;

private:
  void processEvent();
  void processActions(auto &object);
  void processObjects();

private:
  // static const sf::Time TimePerFrame;
  sf::RenderWindow mWindow;
};

#endif // APPLICATION_HPP