#include "sfmlView.hpp"

SFMLView::SFMLView() : mWindow(sf::VideoMode(windowWidth, windowHeight), "Opdracht 5 - Tic Tac Toe",
                               sf::Style::Close) {}

bool SFMLView::loadAssets() {
   if (!this->background_i.loadFromFile("Resources\\background.png"))
      return false;
   if (!this->background_t.loadFromImage(this->background_i))
      return false;
   this->background.setTexture(this->background_t);

   if (!this->board_i.loadFromFile("Resources\\board.png"))
      return false;
   if (!this->board_t.loadFromImage(this->board_i))
      return false;
   this->board.setTexture(this->board_t);
   this->board.setPosition(sf::Vector2f(0.0f, 100.0f));

   if (!this->reset_i.loadFromFile("Resources\\reset.png"))
      return false;
   if (!this->reset_t.loadFromImage(this->reset_i))
      return false;
   this->reset.setTexture(this->reset_t);
   this->reset.setPosition(sf::Vector2f(25.0f, 525.0f));

   if (!this->circle_i.loadFromFile("Resources\\circle.png"))
      return false;
   if (!this->circle.loadFromImage(this->circle_i))
      return false;

   if (!this->cross_i.loadFromFile("Resources\\cross.png"))
      return false;
   if (!this->cross.loadFromImage(this->cross_i))
      return false;

   if (!this->blank_i.loadFromFile("Resources\\blank.png"))
      return false;
   if (!this->blank.loadFromImage(this->blank_i))
      return false;

   if (!this->font.loadFromFile("Resources\\font.ttf"))
      return false;
   this->text.setFont(this->font);
   this->text.setCharacterSize(40);
   text.setFillColor(sf::Color::Black);
   this->text.setPosition(sf::Vector2f(25.0f, 25.0f));

   return true;
}

std::unique_ptr<sf::Sprite> SFMLView::createPiece(const sf::Sprite &piece) {
   std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>(piece);
   return sprite;
}

void SFMLView::keyPress(sf::Vector2f pos) {
   // check if reset button is pressed

   // check if board is pressed
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (pos.x > 10.0f + (i * 140.0f) && pos.x < 150.0f + (i * 140.0f) && pos.y > 110.0f + (j * 140.0f) && pos.y < 250.0f + (j * 140.0f)) {
            std::cout << "x: " << i << " y: " << j << std::endl;
            game.handleMove(i, j);
         }
      }
   }
   if (reset.getGlobalBounds().contains(pos)) {
      game.undoLastMove();
   }
}

void SFMLView::processPieces() {
   std::vector<std::shared_ptr<Tile>> moves = game.getMoves();
   bool cellEmpty = true;

   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         for (auto &move : moves) {
            if (move->getX() == i && move->getY() == j) {
               if (move->getPlayer() == Player::O) {
                  objects.push_back(createPiece(sf::Sprite(this->circle)));
               } else {
                  objects.push_back(createPiece(sf::Sprite(this->cross)));
               }
               cellEmpty = false;
            }
         }
         if (cellEmpty) {
            objects.push_back(createPiece(sf::Sprite(this->blank)));
         }
         cellEmpty = true;
      }
   }
   for (int i = 0; i < 9; i++) {
      objects[i]->setPosition(sf::Vector2f(10.0f + (i / 3) * 140.0f, 110.0f + (i % 3) * 140.0f));
      mWindow.draw(*objects[i]);
   }
   objects.clear();
}

void SFMLView::processText() {
   if (game.detectWinner()) {
      if (game.getWinner() == Player::O) {
         this->text.setString("Player O won!");
      } else {
         this->text.setString("Player X won!");
      }
   } else {
      this->text.setString("Player " + std::string(game.getCurrentPlayer() == Player::O ? "O" : "X") + "'s turn");
   }

   mWindow.draw(this->text);
}

void SFMLView::runGame() {
   if (!loadAssets()) {
      std::cout << "Error loading assets!" << std::endl;
      system("pause");
      return;
   }

   while (mWindow.isOpen()) {
      mWindow.clear();
      mWindow.draw(this->background);
      mWindow.draw(this->board);
      mWindow.draw(this->reset);

      if (!game.detectWinner() || game.getMoves().size() < 9) {
         processPieces();
         processText();
         mWindow.display();
      }
      sf::Event event;
      while (mWindow.pollEvent(event)) {
         if (event.type == sf::Event::Closed)
            mWindow.close();

         if (event.type == sf::Event::MouseButtonPressed)
            if (event.mouseButton.button == sf::Mouse::Button::Left)
               keyPress(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow)));
      }
   }
}