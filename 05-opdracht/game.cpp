#include "game.hpp"

void Game::undoLastMove() {
   std::cout << "Undoing last move" << std::endl;
   if (!moves.empty()) {
      moves.pop_back();
      currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
   }
}

bool Game::checkMove(int x, int y) {
   if (x < 0 || x > 2 || y < 0 || y > 2) {
      return false;
   }
   for (auto obj : moves) {
      if (obj->getX() == x && obj->getY() == y) {
         return false;
      }
   }
   return true;
}

void Game::handleMove(int x, int y) {
   Tile move(x, y, currentPlayer);
   moves.push_back(std::make_shared<Tile>(move));
   currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
}

bool Game::detectWinner() {
   // check if there is a winner
   // Create a vector to store the counts of moves made by each player
   std::vector<int> counts(2);
   int boardSize = 3;

   // Iterate through all the rows
   for (int i = 0; i < boardSize; i++) {
      // Iterate through all the columns
      for (int j = 0; j < boardSize; j++) {
         // Check if the current cell is filled
         auto it = find_if(moves.begin(), moves.end(), [i, j](const auto& move) {
            return move->getX() == i && move->getY() == j;
         });

         if (it != moves.end()) {
            // Increase the count of the player who made the move
            if ((*it)->getPlayer() == Player::X)
               counts[0]++;
            else if ((*it)->getPlayer() == Player::O)
               counts[1]++;
         }
      }

      // Check if any of the players have made the maximum number of moves in the row
      if (counts[0] == boardSize || counts[1] == boardSize) {
         return true;
      }

      // Reset the counts for the next row
      counts[0] = 0;
      counts[1] = 0;
   }

   // Iterate through all the columns
   for (int j = 0; j < boardSize; j++) {
      // Iterate through all the rows
      for (int i = 0; i < boardSize; i++) {
         // Check if the current cell is filled
         auto it = find_if(moves.begin(), moves.end(), [i, j](const auto& move) {
            return move->getX() == i && move->getY() == j;
         });

         if (it != moves.end()) {
            // Increase the count of the player who made the move
            // Increase the count of the player who made the move
            if ((*it)->getPlayer() == Player::X)
               counts[0]++;
            else if ((*it)->getPlayer() == Player::O)
               counts[1]++;
         }
      }

      // Check if any of the players have made the maximum number of moves in the column
      if (counts[0] == boardSize || counts[1] == boardSize) {
         return true;
      }

      // Reset the counts for the next column
      counts[0] = 0;
      counts[1] = 0;
   }

   // Check the diagonal from top-left to bottom-right
   for (int i = 0; i < boardSize; i++) {
      // Check if the current cell is filled
      auto it = find_if(moves.begin(), moves.end(), [i](const auto& move) {
         return move->getX() == i && move->getY() == i;
      });

      if (it != moves.end()) {
         // Increase the count of the player who made the move
         // Increase the count of the player who made the move
         if ((*it)->getPlayer() == Player::X)
            counts[0]++;
         else if ((*it)->getPlayer() == Player::O)
            counts[1]++;
      }
   }

   // Check if any of the players have made the maximum number of moves in the diagonal
   if (counts[0] == boardSize || counts[1] == boardSize) {
      return true;
   }

   // Reset the counts
   counts[0] = 0;
   counts[1] = 0;

   // Check the diagonal from top-right to bottom-left
   for (int i = 0; i < boardSize; i++) {
      // Check if the current cell is filled
      auto it = find_if(moves.begin(), moves.end(), [i, boardSize](const auto& move) {
         return move->getX() == i && move->getY() == boardSize - i - 1;
      });

      if (it != moves.end()) {
         // Increase the count of the player who made the move
         // Increase the count of the player who made the move
         if ((*it)->getPlayer() == Player::X)
            counts[0]++;
         else if ((*it)->getPlayer() == Player::O)
            counts[1]++;
      }

      // Check the diagonal from top-right to bottom-left
      for (int i = 0; i < boardSize; i++) {
         // Check if the current cell is filled
         auto it = find_if(moves.begin(), moves.end(), [i, boardSize](const auto& move) {
            return move->getX() == i && move->getY() == boardSize - i - 1;
         });

         if (it != moves.end()) {
            // Increase the count of the player who made the move
            if ((*it)->getPlayer() == Player::X)
               counts[0]++;
            else if ((*it)->getPlayer() == Player::O)
               counts[1]++;
         }
      }

      // Check if any of the players have made the maximum number of moves in the diagonal
      if (counts[0] == boardSize || counts[1] == boardSize) {
         return true;
      }

      // If none of the checks returned true, then there is no winner
      return false;
   }

   // Check if any of the players have made the maximum number of moves in the diagonal
   if (counts[0] == boardSize || counts[1] == boardSize) {
      return true;
   }

   // If none of the checks returned true, then there is no winner
   return false;
}

Player Game::getWinner() {
   // return the winner
   return lastPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
}