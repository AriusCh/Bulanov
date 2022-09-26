#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;
    std::string enteredChars = "";

    std::string wordHidden(word.size(), '-');

    bool winStatus = false;
    bool loseStatus = false;
    std::string wordCopy = word;
    while (!winStatus && !loseStatus) {
        std::cout << wordHidden << std::endl << "Enter letter: ";
        std::string attempt;
        std::cin >> attempt;
        if (attempt.size() > 1) {
            if (attempt == wordCopy) {
                winStatus = true;
            } else {
                loseStatus = true;
            }
        } else if (attempt.size() == 1){
            char c = attempt[0];
            if (std::find(enteredChars.cbegin(), enteredChars.cend(), c) != enteredChars.cend()) {
                std::cout << "You have already entered " << c << std::endl;
                continue;
            }
            enteredChars += c;
            if (std::find(word.cbegin(), word.cend(), c) == word.cend()) {
                std::cout << "No such letter!" << std::endl;
                continue;
            }
            do {
                auto it = std::find(word.begin(), word.end(), c);
                *(wordHidden.begin() + (it - word.cbegin())) = c;
                *it = '-';
            }
            while (std::find(word.cbegin(), word.cend(), c) != word.cend());
            if (std::find(wordHidden.cbegin(), wordHidden.cend(), '-') == wordHidden.cend()) {
                winStatus = true;
            }    
        }
        
    }
    if (winStatus) {
        std::cout << "Your word is: " << wordCopy << "! Congratulations!" << std::endl;
    }
    if (loseStatus) {
        std::cout << "You lost! The hidden word was: " << wordCopy << std::endl;
    }

    return 0;
}
