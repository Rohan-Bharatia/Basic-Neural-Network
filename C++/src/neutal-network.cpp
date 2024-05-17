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

#include "include/neural-network.hpp"

Nueral_Network::Nueral_Network(std::vector<uint32_t> topology, float learning_rate = 1.0f)
                               : topology(topology), weight_matricies({}), value_matricies({}),
                               bias_matricies({}), learning_rate(learning_rate)
{
    for(uint32_t i = 0; i < topology.size(); i++)
    {
        Matrix<float> weight_matrix(topology[i + 1], topology[i]);
        weight_matrix = weight_matrix.apply_function([](const float &val)
        { return static_cast<float>(std::rand()) / std::RAND_MAX });

        weight_matricies.push_back(weight_matrix);

        Matrix<float> bias_matrix(topology[i + 1], 1);
        bias_matrix = bias_matrix.apply_function([](const float &val)
        { return static_cast<float>(std::rand()) / std::RAND_MAX });

        bias_matricies.push_back(bias_matrix);
    }

    value_matricies.resize(topology.size());
}

bool Nueral_Network::feed_forward(std::vector<float> input)
{
    if(input.size() != topology[0])
        return false;

    Matrix<float> vals(input.size(), 1);

    for(uint32_t i = 0; i < input.size(); i++)
        vals.values[i] = input[i];

    for(uint32_t i = 0; i < weight_matricies.size(); i++)
    {
        value_matricies[i] = vals;
        vals = vals.multiply(weight_matricies[i]);
        vals = vals.add(bias_matricies[i]);
        vals = vals.apply_function(sigmoid);
    }

    value_matricies[weight_matricies.size()] = vals;

    return true;
}

bool Nueral_Network::back_propegate(std::vector<float> output_target)
{
    if(output_target.size() != topology.size())
        return false;

    Matrix<float> errors(target_output.size(), 1);
    errors.values = target_output;
    errors = errors.add(value_matricies.back().flip_signs());

    for(uint32_t i = 0; i < weight_matricies.size() - 1; i>= 0; i--)
    {
        Matrix<float> previous = errors.multiply(weight_matricies[i].transpose());
        Matrix<float> outputs = value_matricies[i + 1].apply_function(derivative_sigmoid);
        Matrix<float> gradients = errors.multiply(outputs);
        gradients = gradients.multiply(learning_rate);
        Matrix<float> wieght_gradients = value_matricies[i].transpose().multiply(gradients);

        bias_matricies[i] = bias_matricies[i].add(gradients);
        weight_matricies[i] = weight_matricies[i].add(weight_gradients);
        errors = previous;
    }

    return true;
}

#endif