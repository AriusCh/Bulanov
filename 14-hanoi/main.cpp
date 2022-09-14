#include <iostream>
#include <ostream>

void hanoi(int n, int first, int second, int third) {
    if (n == 1) {
        std::cout << first << " -> " << third << std::endl;
    } else {
        hanoi(n - 1, first, third, second);
        std::cout << first << " -> " << third << std::endl;
        hanoi(n - 1, second, first, third);
    }
}

int main() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    hanoi(N, 1, 2, 3);
    
    return 0;
}
