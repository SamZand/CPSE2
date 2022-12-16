#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<char> readCharactersFromFile(const std::string &filePath) {
  std::vector<char> characters;

  std::ifstream file(filePath);

  if (file.is_open()) {
    char c;
    while (file.get(c)) {
      characters.push_back(c);
    }
    file.close();

  } else {
    std::cout << "Failed to open file: " << filePath << std::endl;
  }
  return characters;
}

std::vector<char> makeCharactersLowercase(const std::vector<char> &characters) {
  std::vector<char> lowercaseCharacters;

  std::transform(characters.begin(), characters.end(),
                 std::back_inserter(lowercaseCharacters), tolower);

  return lowercaseCharacters;
}

std::map<char, int> countLetters(const std::vector<char> &characters) {
  std::map<char, int> letterCounts;
  for (const char &c : characters) {
    if (std::isalpha(c)) {
      ++letterCounts[c];
    }
  }
  return letterCounts;
}
std::map<std::string, int> countWords(const std::vector<char> &characters) {
  std::map<std::string, int> wordCounts;
  std::string word;
  for (const char &c : characters) {
    if (std::isalpha(c)) {
      word += c;
    } else {
      if (!word.empty()) {
        ++wordCounts[word];
        word.clear();
      }
    }
  }
  return wordCounts;
}

template <typename A, typename B>
std::multimap<B, A> flip_multimap(const std::map<A, B> &src) {
  std::multimap<B, A> dst;
  for (const auto &kv : src) {
    dst.insert(std::make_pair(kv.second, kv.first));
  }
  return dst;
}

int main() {
  const std::string fileName = "bible.txt";
  std::vector<char> charVector = readCharactersFromFile(fileName);
  std::vector<char> smallChar = makeCharactersLowercase(charVector);
  std::map<char, int> letterCounts = countLetters(smallChar);
  std::map<std::string, int> wordCounts = countWords(smallChar);
  std::multimap<int, char> flippedLetterCounts = flip_multimap(letterCounts);
  std::multimap<int, std::string> flippedWordCounts = flip_multimap(wordCounts);

  std::cout << "\nOpdracht 4 - STL \n"
            << std::endl
            << "Number of characters:   " << charVector.size() << std::endl
            << "Number of lines:        "
            << std::count(charVector.begin(), charVector.end(), '\n')
            << std::endl
            << "Number of alphabetic:   "
            << std::count_if(charVector.begin(), charVector.end(), isalpha)
            << std::endl;

  std::cout << std::endl << "Count sorted letters: " << std::endl;

  for (auto it = flippedLetterCounts.rbegin(); it != flippedLetterCounts.rend();
       it++) {
    std::cout << it->second << "\t appears \t" << it->first << " times."
              << std::endl;
  }

  std::cout << std::endl << "Count sorted words: " << std::endl;

  int i = 0;
  for (auto it = flippedWordCounts.rbegin(); it != flippedWordCounts.rend();
       it++) {
    std::cout << it->second << "\t appears \t" << it->first << " times."
              << std::endl;
    if (i++ > 10)
      break;
  }

  return 0;
}