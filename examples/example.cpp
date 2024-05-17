#pragma region LICENSE

// MIT License

// Copyright (c) 2024 Rohan Bharatia

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma endregion LICENSE

#pragma once

#ifndef EXAMPLE_CPP
#define EXAMPLE_CPP

// std
#include <iostream>
#include <vector>
#include <cstdio>

#include "C++/include/neural-network.hpp"

int main(int argc, char *argv[])
{
    std::vector<uint32_t> topology = {2, 3, 1};
    Nueral_Network nn(topology, 0.1);
    std::vector<std::vector<float>> inputs =
    { {0.0f, 0.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 1.0f} };
    std::vector<std::vector<float>> outputs =
    { {0.0f}, {0.0f}, {1.0f}, {1.0f} };
    uint32_t epoch = 100000;

    std::cout << "Training Started!" << std::endl;

    for(uint32_t i = 0; i < epoch; i++)
    {
        uint32_t idx = std::rand() % 4;

        nn.feed_forward(inputs[idx]);
        nn.back_propegate(outputs[idx]);
    }

    std::cout << "Training Complete!" << std::endl;

    for(std::vector<float> input : inputs)
    {
        nn.feed_forward(input);

        std::vector<float> predictions = nn.get_predictions();

        std::cout << "Prediction: " << input[0] << ", " << input[1] << " => " << predictions[0] << std::endl;
    }

    return 0;
}

#endif