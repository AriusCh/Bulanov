#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;

    std::string wordHidden(word.size(), '-');

    bool isRevealed = false;
    while (!isRevealed) {
        std::cout << wordHidden << std::endl << "Enter letter: ";
        char c;
        std::cin >> c;
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
            isRevealed = true;
        }
    }
    std::cout << "Your word is: " << wordHidden << "! Congratulations!" << std::endl;

    return 0;
}
