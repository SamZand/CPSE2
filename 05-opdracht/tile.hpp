#ifndef _TILE_HPP
#define _TILE_HPP

#include <iostream>

enum class Player { X,
                    O,
                    None };

inline std::ostream& operator<<(std::ostream& os, Player player) {
   switch (player) {
      case Player::X:
         os << "X";
         break;
      case Player::O:
         os << "O";
         break;
      case Player::None:
         os << " ";
         break;
   }
   return os;
}

class Tile {
  private:
   int x, y;
   Player player;

  public:
   Tile(int x, int y, Player player) : x(x), y(y), player(player) {}
   int getX() { return x; }
   int getY() { return y; }
   Player getPlayer() { return player; }
};

#endif  // _TILE_HPP