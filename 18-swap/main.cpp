#include <iostream>

void swap1(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}

void swap2(int& a, int& b) {
    b = a + b;
    a = b - a;
    b = b - a;
}

void swap3(int &a, int& b) {
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}

struct structInt {
    int a;
    int b;
};

void swap4(structInt & nums) {
    nums.b = nums.a + nums.b;
    nums.a = nums.b - nums.a;
    nums.b = nums.b - nums.a;
}

int main() {
    int a = 1, b = 2;

    std::cout << "Before swap: " << a << " " << b << "\n";
    
    swap1(a, b);
    std::cout << "swap1: " << a << " " << b << "\n";

    swap2(a, b);
    std::cout << "swap2: " << a << " " << b << "\n";

    swap3(a, b);
    std::cout << "swap3: " << a << " " << b << "\n";

    structInt nums = {1, 2};
    swap4(nums);
    std::cout << "swap4: " << nums.a << " " << nums.b << "\n";

    
    return 0;
}
