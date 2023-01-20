#ifndef __TICTACTOECONTROLLER_HPP
#define __TICTACTOECONTROLLER_HPP

#include "sfmlView.hpp"
#include "textView.hpp"

// Controller object
template <typename T>
class TicTacToeController {
  private:
   T view;

  public:
   TicTacToeController() : view() { view.runGame(); }

   ~TicTacToeController() {}
};
#endif  // __TICTACTOECONTROLLER_HPP
