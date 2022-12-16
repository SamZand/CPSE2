#include "application.hpp"

std::ifstream &operator>>(std::ifstream &input, sf::Vector2f &rhs) {
  char c;
  if (!(input >> c)) {
    throw endOfFile();
  }
  if (c != '(') {
    throw invalidPosition(c);
  }

  if (!(input >> rhs.x)) {
    input.clear();
    char err;
    input >> err;
    std::cout << err << std::endl;
    throw invalidValue("x position", err);
  }

  if (!(input >> c)) {
    throw endOfFile();
  }

  if (!(input >> rhs.y)) {
    input.clear();
    char err;
    input >> err;
    throw invalidValue("y position", err);
  }

  if (!(input >> c)) {
    throw endOfFile();
  }

  if (c != ')') {
    throw invalidPosition(c);
  }

  return input;
}

std::ifstream &operator>>(std::ifstream &input, sf::Color &rhs) {
  std::string s;
  input >> s;
  for (auto const &color : colors) {
    if (color.name == s) {
      rhs = color.color;
      return input;
    }
  }
  throw invalidColor(s);
}

std::unique_ptr<Figure> createScreenObject(std::ifstream &input) {
  sf::Vector2f position;
  std::string name;
  input >> position >> name;

  if (name == "Circle") {
    sf::Color color;
    float radius;
    input >> color >> radius;
    return std::make_unique<Circle>(position, radius, color);
  } else if (name == "Rectangle") {
    sf::Color color;
    sf::Vector2f size;
    input >> color >> size;
    return std::make_unique<Rectangle>(position, size, color);
  } else if (name == "Line") {
    sf::Color color;
    sf::Vector2f size;
    input >> color >> size;
    return std::make_unique<Line>(position, size, color);
  } else if (name == "Picture") {
    std::string fileName;
    input >> fileName;
    return std::make_unique<Picture>(position, fileName);
  } else if (name == "") {
    throw endOfFile();
  }
  throw invalidFigure(name);
}

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
void Application::makeObjects(const std::string &fileName) {
  std::cout << "Making objects" << std::endl;
  objects.reserve(10);
  int i = 0;

  std::ifstream file(fileName);
  std::string line;
  try {
    while (std::getline(file, line)) {
      objects.emplace_back(createScreenObject(file));
      i++;
      std::cout << "Creating object " << i << std::endl;
    }
  } catch (const endOfFile &e) {
    std::cout << "End of file reached" << std::endl;
  }
  file.close();
}

void Application::processObjects() {
  std::unique_ptr<Figure> *selected;
  for (auto &object : objects) {
    object->update(mWindow);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
      if (object->contain(sf::Mouse::getPosition(mWindow))) {
        selected = &object;
      }
    }
    if (*selected == object) {
      object->selected = true;
      object->jump(sf::Mouse::getPosition(mWindow));

    } else {
      object->selected = false;
    }

    object->update(mWindow);
    object->draw(mWindow);
  }
}

void Application::processActions() {
  action actions[] = {action(sf::Keyboard::Escape, [&]() { mWindow.close(); })};
  for (auto &action : actions) {
    action();
  }
}

void Application::printObjects(const std::string &fileName) {
  std::cout << "Printing objects" << std::endl;
  std::ofstream file(fileName);
  if (!file) {
    std::cout << "Error opening file: " << fileName << std::endl;
    hadError = true;
  }
  for (const auto &object : objects) {
    object->write(file);
    file << std::endl;
  }
  file.close();
}

void Application::run() {
  const std::string fileName = "objectFile.txt";
  const std::string outFileName = "outFile.txt";
  makeObjects(fileName);

  std::cout << "Start opdracht 3 \n";
  while (mWindow.isOpen()) {

    mWindow.clear();
    processEvent();
    processObjects();
    processActions();
    mWindow.display();
    sf::sleep(sf::milliseconds(20));
  }
  if (hadError) {
    std::cout << "Error in file: objects.txt" << std::endl;
  }
  printObjects(outFileName);

  std::cout << "Terminating application\n";
}