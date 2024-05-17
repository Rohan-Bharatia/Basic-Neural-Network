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

#ifndef MATRIX_CPP
#define MATRIX_CPP

// std
#include <cassert>
#include <iostream>
#include <iomanip>

#include "include/matrix.hpp"

Matrix Matrix::add(Matrix &other)
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
        {
            float result = 0.0f;

            for(uint32_t k = 0; k < cols; k++)
                result += at(k, y) + other.at(k, y);

            target.at(x, y) = result;
        }
    }

    return target;
}

Matrix Matrix::add(float &scalar);
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
            target.at(x, y) = at(x, y) + scalar;
    }
    
    return target;
}

Matrix Matrix::subtract(Matrix &other)
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
        {
            float result = 0.0f;

            for(uint32_t k = 0; k < cols; k++)
                result += at(k, y) - other.at(k, y);

            target.at(x, y) = result;
        }
    }

    return target;
}

Matrix Matrix::subtract(float &scalar);
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
            target.at(x, y) = at(x, y) - scalar;
    }
    
    return target;
}

Matrix Matrix::multiply(Matrix &other)
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
        {
            float result = 0.0f;

            for(uint32_t k = 0; k < cols; k++)
                result += at(k, y) * other.at(k, y);

            target.at(x, y) = result;
        }
    }
    
    return target;
}

Matrix Matrix::multiply(float &scalar);
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
            target.at(x, y) = at(x, y) * scalar;
    }
    
    return target;
}

Matrix Matrix::divide(Matrix &other)
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
        {
            if(target.at(x, y) != 0)
            {
                float result = 0.0f;

                for(uint32_t k = 0; k < cols; k++)
                    result += at(k, y) / other.at(k, y);

                target.at(x, y) = result;
            }
            else
            {
                std::runtime_error("Unable divide by zero!");
                return EXIT_FAILURE;
            }
        }
    }

    return target;
}

Matrix Matrix::divide(float &scalar);
{
    assert(cols == other.rows);
    
    Matrix target(other.cols, other.rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
        {
            if(scalar != 0)
                target.at(x, y) = at(x, y) / scalar;
            else
            {
                std::runtime_error("Unable to divide by zero!");
                return EXIT_FAILURE;
            }
        }
    }
    
    return target;
}

Matrix Matrix::flip_signs()
{
    Matrix target(cols, rows);

    for(uint32_t x = 0; x < target.cols; x++)
    {
        for(uint32_t y = 0; y < target.rows; y++)
            target.at(x, y) = -at(x, y);
    }
    
    return target;
}

Matrix Matrix::transpose()
{
    Matrix target(cols, rows);

    for(uint32_t x = 0; x < cols; x++)
    {
        for(uint32_t y = 0; y < rows; y++)
            target.at(x, y) = at(y, x);
    }
    
    return target;
}

template<typename T>
Matrix Matrix::apply_function(std::function<T(const T&)> func)
{
    Matrix target(cols, rows);

    for(uint32_t x = 0; x < cols; x++)
    {
        for(uint32_t y = 0; y < rows; y++)
            target.at(x, y) = func(at(x, y));
    }

    return target;
}

Matrix Matrix::cofactor(uint32_t col, uint32_t row)
{
    Matrix target(cols - 1, rows - 1);
    uint32_t idx = 0;

    for(uint32_t x = 0; x < cols; x++)
    {
        for(uint32_t y = 0; y < rows; y++)
        {
            if(x == col || y == row)
                continue;

            target.values[idx++] = at(x, y);
        }
    }

    return target;
}

template<typename T>
T Matrix::determinant()
{
    assert(rows == cols);
    T target();

    if(rows == 1)
        return values[0];
    else
    {
        uint32_t sign = 1;

        for(uint32_t x = 0; x < cols; x++)
        {
            target += sign * at(x, 0) * cofactor(x, 0).determinant();
            sign *= -1;
        }
    }

    return target;
}

Matrix Matrix::adjoint()
{
    assert(rows == cols);

    Matrix target(cols, rows);
    uint32_t sign = 1;

    for(uint32_t x = 0; x < cols; x++)
    {
        for(uint32_t y = 0; y < rows; y++)
        {
            target.at(x, y) += sign * cofactor(x, y).determinant();
            sign *= -1;
        }
    }
    
    return target.transpose();
}

template<typename T>
Matrix Matrix::inverse()
{
    Matrix adj = adjoint();
    T factor = determinant();

    for(uint32_t x = 0; x < col; x++)
    {
        for(uint32_t x = 0; x < col; x++)
            adj.at(x, y) /= factor;
    }

    return adj;
}

Mat2x2::Mat2x2()
{
    Matrix matrix(2, 2);
    return matrix;
}

Mat3x3::Mat3x3()
{
    Matrix matrix(3, 3);
    return matrix;
}

Mat4x4::Mat4x4()
{
    Matrix matrix(4, 4);
    return matrix;
}

#endif