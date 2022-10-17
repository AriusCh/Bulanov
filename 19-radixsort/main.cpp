#include <iostream>
#include <vector>

void radixSort(std::vector<unsigned int> &vec) {
    auto n = vec.size();
    if (n <= 1)
        return;

    std::vector<unsigned int> output(n);
    std::vector<int> count(256);



    for (int shift = 0, s = 0; shift<4; shift++, s+=8) {
        for (auto num : count) {
            num = 0;
        }

        for (int i = 0; i < n; i++) {
            count[(vec[i] >> s) & 0xff]++;
        }

        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int idx = (vec[i] >> s) & 0xff;
            output[--count[idx]] = vec[i];
        }

        std::vector<unsigned int> tmp = std::move(vec);
        vec = std::move(output);
        output = std::move(tmp);
    }
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::vector<unsigned int> vec(n);

    for (auto &num : vec) {
        std::cin >> num;
    }

    std::cout << "\n";
    std::cout << "Original array: ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    radixSort(vec);
    std::cout << "Sorted array: ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    return 0;
}
