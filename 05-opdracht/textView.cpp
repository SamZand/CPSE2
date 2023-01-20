#include "textView.hpp"

TextView::TextView() {}

void TextView::handleTextMove() {
   std::cout << "Current player: " << game.getCurrentPlayer() << std::endl;
   int x, y;
   std::cout << "Enter x coordinate: ";
   std::cin >> x;
   std::cout << "Enter y coordinate: ";
   std::cin >> y;
   if (game.checkMove(x, y)) {
      game.handleMove(x, y);
      if (!game.detectWinner()) {
         std::string undo;
         std::cout << "Do you want to undo? (y/n)";
         std::cin >> undo;
         if (undo == "y") {
            game.undoLastMove();
         }
      }
   } else {
      std::cout << "This move is not allowed" << std::endl;
   }
}

void TextView::displayBoard() {
   std::vector<std::shared_ptr<Tile>> moves = game.getMoves();
   std::string cellLine = "     |     |     ";
   std::string cellLineWithDash = "_____|_____|_____";
   bool cellEmpty = true;
   std::cout << cellLine << std::endl;

   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         for (auto obj : moves) {
            if (obj->getX() == i && obj->getY() == j && j < 2) {
               std::cout << "  " << obj->getPlayer() << "  |";
               cellEmpty = false;
            } else if (obj->getX() == i && obj->getY() == j && j == 2) {
               std::cout << "  " << obj->getPlayer() << "   ";
               cellEmpty = false;
            }
         }
         if (cellEmpty && j < 2) {
            std::cout << "     |";
         } else if (cellEmpty && j == 2) {
            std::cout << "     ";
         }
         cellEmpty = true;
      }
      std::cout << std::endl;
      if (i < 2) {
         std::cout << cellLineWithDash << std::endl;
         std::cout << cellLine << std::endl;
      }
   }
   std::cout << cellLine << std::endl;
}

void TextView::runGame() {
   while (!game.detectWinner()) {
      displayBoard();
      handleTextMove();
   }
   displayBoard();
   std::cout << "Winner is: " << game.getWinner() << std::endl;
}
