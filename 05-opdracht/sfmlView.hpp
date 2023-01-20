#ifndef __SFMLVIEW_HPP
#define __SFMLVIEW_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "game.hpp"
#include "tile.hpp"

// View object
class SFMLView {
  private:
   unsigned const int windowWidth = 400;
   unsigned const int windowHeight = 600;

  public:
   Game game;
   sf::Sprite background;
   sf::Sprite board;
   sf::Sprite reset;
   std::vector<std::unique_ptr<sf::Sprite>> objects;
   sf::Text text;

   SFMLView();
   void runGame();
   bool loadAssets();
   std::unique_ptr<sf::Sprite> createPiece(const sf::Sprite &piece);
   void processPieces();
   void processText();
   void keyPress(sf::Vector2f pos);

  private:
   sf::RenderWindow mWindow;
   sf::Image background_i;
   sf::Texture background_t;
   sf::Image board_i;
   sf::Texture board_t;
   sf::Image reset_i;
   sf::Texture reset_t;
   sf::Image cross_i;
   sf::Texture cross;
   sf::Image circle_i;
   sf::Texture circle;
   sf::Image blank_i;
   sf::Texture blank;
   sf::Font font;
};

#endif  // __SFMLVIEW_HPP
