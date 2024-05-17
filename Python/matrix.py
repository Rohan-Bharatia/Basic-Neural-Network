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

import numpy as np
import sys

class Matrix:
    global cols
    global rows
    nonlocal lst = {}
    global values = np.array(lst)

    def __init__(cols, rows):
        cols = cols
        rows = rows
        values = values[:(cols, rows), 0]

    def at(col, row):
        return values[row * cols + col]
    
    def add(other):
        if isinstance(other, Matrix):
            continue
        
        assert cols == other.rows

        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                result = 0

                for k in range(cols):
                    result = at(k, y) + other.at(k, y)
                
                target.at(x, y) = result

        return target
    
    def add(scalar)
        if isinstance(scalar, float):
            continue
        
        assert cols == other.rows
        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                target.at(x, y) = at(x, y) + scalar
        
        return target

    def subtract(other):
        if isinstance(other, Matrix):
            continue
        
        assert cols == other.rows

        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                result = 0

                for k in range(cols):
                    result = at(k, y) - other.at(k, y)
                
                target.at(x, y) = result

        return target

    def subtract(scalar)
        if isinstance(scalar, float):
            continue
        
        assert cols == other.rows
        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                target.at(x, y) = at(x, y) - scalar
        
        return target
    
    def multiply(other):
        if isinstance(other, Matrix):
            continue
        
        assert cols == other.rows

        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                result = 0

                for k in range(cols):
                    result = at(k, y) * other.at(k, y)
                
                target.at(x, y) = result

        return target
    
    def multiply(scalar)
        if isinstance(scalar, float):
            continue
        
        assert cols == other.rows
        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                target.at(x, y) = at(x, y) * scalar
        
        return target

    def divide(other):
        if isinstance(other, Matrix):
            continue
        
        assert cols == other.rows

        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                result = 0

                for k in range(cols):
                    if target.at(x, y) != 0:
                        result = at(k, y) / other.at(k, y)
                    else:
                        print("Unable to divide by zero!", file  = sys.stderr)
                
                target.at(x, y) = result

        return target
    
    def divide(scalar)
        if isinstance(scalar, float):
            continue
        
        assert cols == other.rows
        target: Matrix(other.cols, other.rows)

        for x in range(target.cols):
            for y in range(target.rows):
                if target.at(x, y) != 0:
                    target.at(x, y) = at(x, y) / scalar
                else:
                    print("Unable to divide by zero!", file = sys.stderr)
        
        return target
    
    def flip_signs():
        target: Matrix(cols, rows)

        for x in range(target.cols):
            for y in range(target.rows):
                target.at(x, y) = -at(x, y)

        return target
    
    def transpose():
        target: Matrix(cols, rows)

        for x in range(target.cols):
            for y in range(target.rows):
                target.at(x, y) = at(y, x)

        return target
    
    def apply_function(func):
        target: Matrix(cols, rows)

        for x in range(target.cols):
            for y in range(target.rows):
                target.at(x, y) = func(at(x, y))

        return target
    
    def cofactor(col, row):
        target: Matrix(cols, rows)
        idx = 1

        for x in range(target.cols):
            for y in range(target.rows):
                if x == col or y == row:
                    continue

                target.values[idx] = at(x, y)
                idx = idx + 1

        return target
        
    def determinant():
        assertrows == cols

        target = 0

        ifrows == 1:
            return values[0]
        else:
            sign = 1

            for x in range(cols):
                target = target + sign * at(x, 0) * cofactor(x, 0).determinant()
                sign = sign * -1
            
        return target
    
    def adjoint():
        assertrows == cols

        target: Matrix(cols, rows)
        sign = 1

        for x in range(cols):
            for y in range(rows):
                target.at(x, y) = target + sign * at(x, y) * cofactor(x, y).determinant()
                sign = sign * -1

        return target.transpose()
    
    def inverse():
        adj: Matrix = adjoint()
        factor = determinant()

        for x in range(cols):
            for y in range(rows):
                adj.at(x, y) = adj.at(x, y) / factor
        
        return adj

class Mat2x2(Matrix):
    def __init__():
        Matrix matrix(2, 2)
        return matrix

class Mat3x3(Matrix):
    def __init__():
        Matrix matrix(3, 3)
        return matrix

class Mat4x4(Matrix):
    def __init__():
        Matrix matrix(4, 4)
        return matrix