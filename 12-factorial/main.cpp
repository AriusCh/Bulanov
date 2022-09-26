#include <iostream>
#include <stdexcept>
#include <cmath>

int read_number() {
    int output;

    bool taskComplete = false;
    while (!taskComplete) {
        std::string s_num;
        std::cout << "Enter number: ";
        std::cin >> s_num;
        double d_num;
        try {
            d_num = stod(s_num);
        }
        catch (const std::invalid_argument e) {
            std::cout << "Not a number. Try again." << std::endl;
            continue;
        }
        if (d_num != std::floor(d_num)) {
            std::cout << "Not an integer number. Try again." << std::endl;
            continue;
        }
        if (d_num < 0) {
            std::cout << "Number is negative. Try again." << std::endl;
            continue;
        }
        if (d_num > 100000) {
            std::cout << "Number is too large. Try again." << std::endl;
        }
        output = d_num;
        taskComplete = true;
    }
    return output;;
}

int main() {
    int num = read_number();
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    std::cout << num << "! is " << fact << std::endl;

    return 0;
}
