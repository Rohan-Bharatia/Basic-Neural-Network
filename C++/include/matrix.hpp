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

#ifndef MATRIX_HPP
#define MATRIX_HPP

// std
#include <vector>
#include <cmath>
#include <functional>

class Matrix
{
public:
    static constexpr uint32_t cols;
    static constexpr uint32_t rows;
    static constexpr std::vector<float> values;

    Matrix(uint32_t cols, uint32_t rows) : cols(cols), rows(rows), values({})
    { values.resize(cols * rows, 0.0f); }

    float &at(uint32_t col, uint32_t row)
    { return values[row * cols + col]; }

    Matrix add(Matrix &other);
    Matrix add(float &scalar);
    Matrix subtract(Matrix &other);
    Matrix subtract(float &scalar);
    Matrix multiply(Matrix &other);
    Matrix multiply(float &scalar);
    Matrix divide(Matrix &other);
    Matrix divide(float &scalar);

    Matrix flip_signs();

    Matrix transpose();

    bool is_square()
    { return rows == cols; }

    template<typename T>
    Matrix apply_function(std::function<T(const T&)> func);

    Matrix cofactor(uint32_t col, uint32_t row);

    template<typename T>
    T determinant();

    Matrix adjoint();

    Matrix inverse();
};

class Mat2x2 : public Matrix
{
public:
    Mat2x2();
}

class Mat3x3 : public Matrix
{
public:
    Mat3x3();
}

class Mat4x4 : public Matrix
{
public:
    Mat4x4()
}

#endif