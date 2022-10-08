#include <iostream>

#include "neuron.h"

int main() {
    neuron Neuron1({1.f, 2.f, 3.f}, false);
    neuron Neuron2({1.f, 2.f, 3.f}, true);

    std::cout << Neuron1.calc({1.f, 2.f, 3.f}) << std::endl;
    std::cout << Neuron2.calc({1.f, 2.f, 3.f}) << std::endl;

    return 0;
}
