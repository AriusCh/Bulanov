#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <map>

int read_number() {
    int output;

    bool task_complete = false;
    while (!task_complete) {
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
        if (d_num < 1) {
            std::cout << "Number is less than one. Try again." << std::endl;
            continue;
        }
        if (d_num > 100) {
            std::cout << "Number is too large. Try again." << std::endl;
        }
        output = d_num;
        task_complete = true;
    }
    return output;;
}

std::map<int, long> fib_cache;

long fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (fib_cache.find(n) != fib_cache.cend()) {
        return fib_cache[n];
    }
    fib_cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib_cache[n];
}

int main() {
    int num = read_number();
    std::cout << num << "th number in fibonacci sequence is " << fibonacci(num) << std::endl;

    return 0;
}
