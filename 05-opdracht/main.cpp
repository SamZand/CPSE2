#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>

#include "application.hpp"

int main(int argc, char *argv[]) {
   try {
      // Application app;
      if (argc <= 1) {
         std::cout << "Need an argument\n";
      } else if (argc > 1) {
         if (!strcmp(argv[1], "sfml")) {
            std::cout << "sfml\n";
            // app.run();
         } else if (!strcmp(argv[1], "text")) {
            std::cout << "text\n";
            Application().runText();
         }
      }
   } catch (std::exception &e) {
      std::cout << "\nEXCEPTION: " << e.what() << std::endl;
      // }
      return 0;
   }
}