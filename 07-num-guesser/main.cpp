#include <iostream>

int main() {
    int low = 1, high = 100;
    bool number_guessed = false;
    while (!number_guessed) {
        int mid = (low + high) / 2;
        std::cout << "N is greater than " << mid << "? [Yes/No/Equal]: ";
        char c;
        std::cin >> c;
        if (c == 'y' || c == 'Y') {
            low = mid + 1;
        } else if (c == 'n' || c == 'N') {
            high = mid - 1;
        } else if (c == 'e' || c == 'E') {
            number_guessed = true;
            std::cout << "Your number is " << mid << "!" << std::endl;
        } else {
            std::cout << "What?..." << std::endl;
        }
    }

    return 0;
}
