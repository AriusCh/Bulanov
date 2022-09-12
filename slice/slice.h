#pragma once

#include <cstddef>
#include <vector>
#include <memory>

template<class T>
class slice {
    std::vector<T> data;

public:
    slice(const std::vector<T>& input) {
        for (auto it : input) {
             data.push_back(it);
        }
    }

    slice(const std::vector<T>& input, std::size_t start, std::size_t end, int step = 1) {
        if (step > 0) {
            for (auto i = start; i < end; i += step) {
                data.push_back(input[i]);
            }
        } else if (step < 0) {
            for (auto i = start; i > end; i += step) {
                data.push_back(input[i]);
            }
        }
    }

    T& operator[](std::size_t i) {
        return data[i];
    }
    const T& operator[](std::size_t i) const {
        return data[i];
    }

    std::size_t size() const {
        return data.size();
    }
};
