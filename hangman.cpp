#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
  string word, discoveredWord;
  cout << "Please input the word for the hangman game > ";
  cin >> word;
  cout << word << "\n";
  char letter;
  int lives = 3, wordLength = word.length(), wordIterator = wordLength;
  for (int i = 0; i < wordLength; ++i) {
    discoveredWord[i] = '_';
  }
  while (lives && wordIterator) {
    system("CLS");
    cout << "You have > " << lives << " lives left.\n";
    cout << "Word discovery progress > ";
    for (int i = 0; i < wordLength; ++i) {
      cout << discoveredWord[i] << " ";
    }
    cout << "\nWhat letter do you think is missing ? > ";
    cin >> letter;
    bool match = false;
    for (int i = 0; i < wordLength; ++i) {
      if ((letter == word[i] || letter + 32 == word[i] || letter - 32 == word[i]) && discoveredWord[i] != word[i]) {
        discoveredWord[i] = word[i];
        match = true;
        --wordIterator;
      }
    }
    if (wordIterator == 0 && lives != 0) {
      cout << "\nYOU WON! the discovered word is > " << word << flush << "\n";
    }
    if (match == false) {
      --lives;
    }
  }
  if (lives == 0) {
    cout << "\nGAME OVER! You have lost!";
  }
  return 0;
}
