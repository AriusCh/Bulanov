#include <cstddef>
#include <vector>
#include <iostream>

#include "slice.h"

int main() {
    std::vector<int> vec_num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    slice<int> slice1(vec_num);
    slice<int> slice2(vec_num, 2, 5);
    slice<float> slice3({2.5, 2.0, 9.5, 9.0}, 3, 2, -1);
    slice<std::string> slice4({"Hello", "Goodbye", "Biba", "Boba", "Aboba"}, 1, 4, 2);

    for (std::size_t i = 0; i < slice1.size(); i++){
        std::cout << slice1[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < slice2.size(); i++){
        std::cout << slice2[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < slice3.size(); i++){
        std::cout << slice3[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < slice4.size(); i++){
        std::cout << slice4[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
