#include "application.hpp"

// const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application()
    : mWindow(sf::VideoMode(windowWidth, windowHeight), "Opdracht 3",
              sf::Style::Close) {}

void Application::processEvent() {
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      mWindow.close();
    }
  }
}
void Application::processObjects() {
  std::vector<std::unique_ptr<Figure>> objects;
  objects.reserve(10);
  objects.emplace_back(
      createScreenObject("circle", sf::Vector2f(100, 100), sf::Color::Red));
  objects.emplace_back(
      createScreenObject("circle", sf::Vector2f(200, 100), sf::Color::Red));
  std::unique_ptr<Figure> *selected;
  for (auto &object : objects) {
    object->update(mWindow);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
      if (object->contain(sf::Mouse::getPosition(mWindow))) {
        selected = &object;
      }
      if ((*selected) == object) {
        object->selected = true;
        object->jump(sf::Mouse::getPosition(mWindow));

      } else {
        object->selected = false;
      }
    }
    object->draw(mWindow);
  }
}
void Application::processActions(auto &object) {
  action actions[] = {action(sf::Keyboard::Escape, [&]() { mWindow.close(); })};
  for (auto &action : actions) {
    action();
  }
}

void Application::run() {

  while (mWindow.isOpen()) {
    std::cout << "Start opdracht 3 \n";

    mWindow.setFramerateLimit(60);

    while (mWindow.isOpen()) {

      processEvent();

      mWindow.clear();
      processObjects();

      mWindow.display();

      sf::sleep(sf::milliseconds(20));
    }

    std::cout << "Terminating application\n";
  }
}