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

import neural_network
import numpy as np

def main() -> int:
    topology = {2, 3, 1}
    Neural_Network nn(topology, 0.1)
    inputs = { {0, 0}, {1, 1}, {1, 0}, {0, 1} }
    outputs = { {0}, {0}, {1}, {1} }
    epoch = 100000

    print("Training Started!\n")

    for i in range(epoch):
        idx = np.random.rand(4)

        nn.feed_forward(inputs[idx])
        nn.back_propegate(outputs[idx])
    
    print("Training Complete!\n")

    for input_ in inputs:
        nn.feed_forward(input_)

        predictions = nn.get_predictions()

        print("Prediction", input_[0], ", ", input_[1], " => ", predictions[0], "\n")
    return 0