#include <cstddef>
#include <vector>
#include <iostream>

#include "slice.h"

int main() {
    std::vector<int> vec_num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    slice<int> slice_num1(vec_num);
    slice<int> slice_num2(vec_num, 2, 5);
    slice<float> slice_num3({2.5, 2.0, 9.5, 9.0}, 3, 2, -1);

    for (std::size_t i = 0; i < slice_num1.size(); i++){
        std::cout << slice_num1[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < slice_num2.size(); i++){
        std::cout << slice_num2[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < slice_num3.size(); i++){
        std::cout << slice_num3[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
