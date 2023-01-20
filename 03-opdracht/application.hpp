#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "action.hpp"
#include "circle.hpp"
#include "colors.hpp"
#include "exception.hpp"
#include "figure.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "rectangle.hpp"

class Application {
  public:
   Application();
   void run();
   unsigned const int windowWidth = 720;
   unsigned const int windowHeight = 480;

  private:
   sf::RenderWindow mWindow;
   bool hadError = false;
   std::vector<std::unique_ptr<Figure>> objects;

   std::unique_ptr<Figure> createScreenObject(std::ifstream &input);

   void processEvent();
   void processActions();
   void processObjects();
   void makeObjects(const std::string &fileName);
   void printObjects(const std::string &fileName);
};

#endif  // APPLICATION_HPP