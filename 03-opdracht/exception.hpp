#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class endOfFile : public std::exception {
private:
  std::string message = "end of file reached";

public:
  const char *what() const noexcept override { return message.c_str(); }
};

class invalidFigure : public std::exception {
private:
  std::string message;

public:
  invalidFigure(std::string name)
      : message(std::string("unknown Figure \'") + name + "\'" +
                "found in config.txt") {}

  const char *what() const noexcept override { return message.c_str(); }
};

class invalidColor : public std::exception {
private:
  std::string message;

public:
  invalidColor(std::string name)
      : message(std::string("unknown Color  \'") + name + "\'" +
                "found in config.txt") {}

  const char *what() const noexcept override { return message.c_str(); }
};

class invalidPosition : public std::exception {
private:
  std::string message;

public:
  invalidPosition(char c)
      : message(std::string("invalid Position \'") + c + "\'" +
                "found in config.txt") {}

  const char *what() const noexcept override { return message.c_str(); }
};

class invalidValue : public std::exception {
private:
  std::string message;

public:
  invalidValue(std::string valueName, const char &value)
      : message(std::string("invalid Value \'") + valueName + value + "\'" +
                "found in config.txt") {}

  const char *what() const noexcept override { return message.c_str(); }
};

class invalidFile : public std::exception {
private:
  std::string message;

public:
  invalidFile(std::string fileName)
      : message(std::string("invalid File \'") + fileName + "\'" +
                "found in config.txt") {}

  const char *what() const noexcept override { return message.c_str(); }
};

#endif // EXCEPTION_HPP