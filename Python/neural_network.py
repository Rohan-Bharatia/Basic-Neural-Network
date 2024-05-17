# MIT License

# Copyright (c) 2024 Rohan Bharatia

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import matrix
import numpy as np

def sigmoid(x):
    return (1 / (1 + np.exp(-x)))

def derivative_sigmoid(x):
    return (x * (1 - x))

class Nueral_Network:
    nonlocal lst = {}
    global topology: int = np.array(lst)
    global weight_matricies: Matrix: float = np.array(lst)
    global value_matricies: Matrix: float = np.array(lst)
    global bias_matricies: Matrix: float = np.array(lst)
    global learning_rate: float

    def __init__(topology, learning_rate):
        topology = topology
        learning_rate = learning_rate

        for i in range(len(topology)):
            weight_matrix = Matrix(topology[i + 1], topology[i])
            weight_matrix = weight_matrix.apply_function(lambda val : np.random.rand(0, 1) / 0x7fff)
            weight_matricies.append(weight_matrix)

            bias_matrix: Matrix: float = Matrix(topology[i + 1], 1)
            bias_matrix = bias_matricies.apply_function(lambda val : np.random.rand(0, 1) / 0x7fff)
            bias_matricies.append(bias_matrix)
        
        weight_matricies[:len(topology)]
    
    def feed_forward(inputs):
        if isinstance(inputs, {float}):
            continue

        if(len(inputs) != topology[0]):
            return FALSE
        
        vals: Matrix: float = Matrix(len(vals), 1)

        for i in range(vals.cols):
            vals.values[i] = inputs[i]
        
        for i in range(len(weight_matricies)):
            value_matricies[i] = vals
            vals = vals.multiply(weight_matricies[i])
            vals = vals.add(bias_matricies[i])
            vals = vals.apply_function(sigmoid)
        
        value_matricies[len(weight_matricies)] = vals

        return TRUE
    
    def feed_forward(target_output):
        if isinstance(target_output, {float}):
            continue

        if(len(target_output) != len(topology)):
            return FALSE
        
        errors: Matrix: float = Matrix(len(target_output), 1)
        errors.values = target_output
        errors = errors.add(value_matricies[-1].flip_signs())

        for i in range(len(weight_matricies - 1), 0):
            previous: Matrix: float = errors.multiply(weight_matricies[i].transpose())
            outputs: Matrix: float = value_matricies[i + 1].apply_function(derivative_sigmoid)
            gradients: Matrix: float errors.multiply(learning_rate)
            gradients = gradients.multiply(learning_rate)
            weight_gradients: Matrix: float = value_matricies[i].transpose().multiply(gradients)

            bias_matricies[i] = bias_matricies[i].add(gradients)
            weight_matricies[i] = weight_matricies[i].add(weight_gradients)
            errors = previous
        
        return TRUE
    
    def get_predictions():
        return value_matricies.[-1].values