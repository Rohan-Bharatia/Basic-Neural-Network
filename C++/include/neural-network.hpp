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

#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

// std
#include <cstdlib>
#include <vector>
#include <cmath>

#include "matrix.hpp"

inline float sigmoid(float x)
{ return 1 / (1 + std::exp(-x)); }

inline float derivative_sigmoid(float x)
{ return (x * (1 - x)); }

class Nueral_Network
{
public:
    std::vector<uint32_t> topology;
    std::vector<Matrix<float>> weight_matricies;
    std::vector<Matrix<float>> value_matricies;
    std::vector<Matrix<float>> bias_matricies;
    float learning_rate;


    Nueral_Network(std::vector<uint32_t> topology, float learning_rate = 1.0f)
                   : topology(topology), weight_matricies({}), value_matricies({}),
                   bias_matricies({}), learning_rate(learning_rate) {}
    
    bool feed_forward(std::vector<float> input);
    bool back_propegate(std::vector<float> output_target);

    std:vector<float> get_predictions();
};



#endif