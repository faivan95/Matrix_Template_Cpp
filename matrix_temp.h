#pragma once

#include <iostream>
#include <vector>
#include <type_traits>

//bool checkForString(const std::string& str);

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    // Matrix(T tData) {
    //     //data.resize(tData.size());
    //     data.resize(1, 1);
    //     data[0][0] = "Empty";
    // }

    Matrix(size_t rows, size_t cols) {
        this->rows = rows;
        this->cols = cols;
        data.resize(rows, std::vector<T>(cols));
    }

    T& operator()(size_t row, size_t col) {
        return data[row][col];
    }

    const T& operator()(size_t row, size_t col) const {
        return data[row][col];
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }
    
    //Display matrix data
    void displayData() {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << "Data at (" << i << ", " << j << ") is " << data[i][j] << std::endl;
            }
        }
    }

    // Addition Operation
    Matrix<T> operator+(const Matrix<T>& second) const {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + second(i, j);
            }
        }
        return result;
    }

    // Subtraction operation
    Matrix<T> operator-(const Matrix<T>& second) const {
        Matrix<T> result(rows, cols);
        if constexpr (std::is_same<T, std::string>::value) {
            std::cout << "Subtraction operation is not possible with string types in matrices!" << std::endl;
        }
        else {
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result(i, j) = data[i][j] - second(i, j);
                }
            }
        }
        
        return result;
    }

    // Multiplication operation
    Matrix<T> operator*(const Matrix<T>& second) const {
        Matrix<T> result(rows, second.getCols());
        if constexpr (std::is_same<T, std::string>::value) {
            std::cout << "Multiplication operation is not possible with string types in matrices!" << std::endl;
            // Matrix<T> result(0, 0);
            // // result.data("Empty");
            // result(0, 0) = "Empty";
            // return result;

            // Matrix<T> result(rows, second.getCols());
            // for (size_t i = 0; i < rows; ++i) {
            //     for (size_t j = 0; j < second.getCols(); ++j) {
            //         //result(i, j) = 0;
            //         for (size_t k = 0; k < cols; ++k) {
            //             result(i, j) = "Empty ";
            //         }
            //     }
            // }
        }
        else {
            //Matrix<T> result(rows, second.getCols());
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < second.getCols(); ++j) {
                    result(i, j) = 0;
                    for (size_t k = 0; k < cols; ++k) {
                        result(i, j) += data[i][k] * second(k, j);
                        std::cout << data[i][k] << " * " << second(k,j) << " = " << result(i,j) << std::endl;
                    }
                }
            }
        }
        return result;
    }
};
