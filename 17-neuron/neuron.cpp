#include "neuron.h"

#include <cmath>

neuron::neuron() {
    weights = {0.f};
    useSigmoid = false;
}

neuron::neuron(const std::vector<float>& weights, bool useSigmoid) {
    this->weights = weights;
    this->useSigmoid = useSigmoid;
}

float neuron::calc(const std::vector<float>& num) {
    auto n = num.size();
    float output = 0.f;
    for (auto i = n - n; i < n; i++){
        output += weights[i] * num[i];
    }
    output += weights[n];
    if (useSigmoid) {
        output = sigmoid(output);
    }
    return output;
}

float neuron::sigmoid(float x) {
    return 1.f / (1.f + std::exp(-x));
}
