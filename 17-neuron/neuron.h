#pragma once

#include <vector>

class neuron {

public:
    neuron();
    neuron(const std::vector<float>& weights, bool useSigmoid);

    float calc(const std::vector<float>& num);

private:
    std::vector<float> weights;
    bool useSigmoid;

    float sigmoid(float x);

};
