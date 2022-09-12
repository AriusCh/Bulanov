#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

int main() {
    bool complete_flag = 0;
    std::string s_num;
    int num;
    while (!complete_flag) {
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
        double d_num_floored = std::floor(d_num);
        if (d_num_floored != d_num) {
            std::cout << "Not a integer number. Try again." << std::endl;
            continue;
        }
        if (d_num <= 0) {
            std::cout << "Number is less or equal to zero. Try again." << std::endl;
            continue;
        }
        num = d_num;
        complete_flag = 1;
    }
    if (num == 1) {
            std::cout << num << " is a composite number." << std::endl;
            return 0;

    }
    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0 || num == 1) {
            std::cout << num << " is a composite number." << std::endl;
            return 0;
        }
    }
    std::cout << num << " is a prime number." << std::endl;
    return 0;
}
