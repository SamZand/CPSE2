#ifndef __TEXTVIEW_HPP
#define __TEXTVIEW_HPP

#include <iostream>

#include "game.hpp"
#include "tile.hpp"

// View object
class TextView {
  private:
   Game game;

  public:
   TextView();
   void handleTextMove();
   void displayBoard();
   void runGame();
};

#endif  // __TEXTVIEW_HPP