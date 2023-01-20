#ifndef __GAME_HPP
#define __GAME_HPP
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

#include "tile.hpp"

class Game {
  private:
   std::vector<std::shared_ptr<Tile>> moves;  // List of moves
   Player currentPlayer;                      // Current player
   Player lastPlayer;                         // Last player
  public:
   Game() : currentPlayer(Player::X) {
      moves.reserve(9);
   }

   void undoLastMove();
   Player getCurrentPlayer() { return currentPlayer; }
   Player getLastPlayer() { return lastPlayer; }
   std::vector<std::shared_ptr<Tile>> getMoves() { return moves; }
   bool detectWinner();
   Player getWinner();
   bool checkMove(int x, int y);
   void handleMove(int x, int y);

   ~Game() {}
};

#endif  // __GAME_HPP