#include <iostream>

int main() {
    int*** arr = new int**[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new int*[3];
        for (int j = 0; j < 3; j++) {
            arr[i][j] = new int[3];
            for (int k = 0; k < 3; k++) {
                arr[i][j][k] = 1 + k + 3 * j + 9 * i;
                std::cout << arr[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arr[i][j][k] = 1 + (2 - k) + 3 * (2 - j) + 9 * (2 - i);
                std::cout << arr[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
