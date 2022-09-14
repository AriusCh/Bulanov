#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;

    std::string word_hidden(word.size(), '-');

    bool is_revealed = false;
    while (!is_revealed) {
        std::cout << word_hidden << std::endl << "Enter letter: ";
        char c;
        std::cin >> c;
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
            is_revealed = true;
        }
    }
    std::cout << "Your word is: " << word_hidden << "! Congratulations!" << std::endl;

    return 0;
}
