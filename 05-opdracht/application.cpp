#include "application.hpp"

Application::Application() {
}

void Application::runText() {
   // runs TicTacToe in text mode
   system("cls");
   std::cout << "Start opdracht 5 text versie \n"
             << std::flush;

   TicTacToeController<TextView> controller;

   std::cout << "Terminating application\n";
}

void Application::runSFML() {
   // runs TicTacToe in SFML mode
   system("cls");
   std::cout << "Start opdracht 5 SFML versie \n"
             << std::flush;

   TicTacToeController<SFMLView> controller;
}