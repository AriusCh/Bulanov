#include <iostream>
#include <string>

int main() {
    std::string str1, str2;
    std::cout << "Enter string: ";
    std::cin >> str1;
    for (auto c : str1) {
        str2.push_back(c);
    }
    std::cout << "String copy: " << str2 << std::endl;
    return 0;
}
