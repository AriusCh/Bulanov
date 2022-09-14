#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;
    std::string entered_chars = "";

    std::string word_hidden(word.size(), '-');

    bool win_status = false;
    bool lose_status = false;
    std::string word_copy = word;
    while (!win_status && !lose_status) {
        std::cout << word_hidden << std::endl << "Enter letter: ";
        std::string attempt;
        std::cin >> attempt;
        if (attempt.size() > 1) {
            if (attempt == word_copy) {
                win_status = true;
            } else {
                lose_status = true;
            }
        } else if (attempt.size() == 1){
            char c = attempt[0];
            if (std::find(entered_chars.cbegin(), entered_chars.cend(), c) != entered_chars.cend()) {
                std::cout << "You have already entered " << c << std::endl;
                continue;
            }
            entered_chars += c;
            if (std::find(word.cbegin(), word.cend(), c) == word.cend()) {
                std::cout << "No such letter!" << std::endl;
                continue;
            }
            do {
                auto it = std::find(word.begin(), word.end(), c);
                *(word_hidden.begin() + (it - word.cbegin())) = c;
                *it = '-';
            }
            while (std::find(word.cbegin(), word.cend(), c) != word.cend());
            if (std::find(word_hidden.cbegin(), word_hidden.cend(), '-') == word_hidden.cend()) {
                win_status = true;
            }    
        }
        
    }
    if (win_status) {
        std::cout << "Your word is: " << word_hidden << "! Congratulations!" << std::endl;
    }
    if (lose_status) {
        std::cout << "You lost! The hidden word was: " << word_copy << std::endl;
    }

    return 0;
}
