#include "matrix_temp.h"
#include <iostream>
#include <tuple>

std::tuple<size_t, size_t> matrixDimensions() {
    std::cout << "What is the dimension of the first matrix? " << std::endl 
                    << "Please enter {no. of rows} and {no. of columns} with a space or enter in-between:" << std::endl;
    
    size_t num_rows, num_cols;
    std::cin >> num_rows >> num_cols;
    return {num_rows, num_cols};
}

void populateMatrix(size_t rows, size_t cols, Matrix<int>& mat, int matrixNo) {
    std::string temp;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Input the data at " << i << " " << j << " of matrix " << matrixNo << ": " << std::endl;
            std::cin >> temp;  
            mat(i, j) = std::stoi(temp);
        }
    }
}

void populateMatrix(size_t rows, size_t cols, Matrix<std::string>& mat, int matrixNo) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Input the data at " << i << " " << j << " of matrix " << matrixNo << ": " << std::endl;
            std::cin >> mat(i, j);
        }
    }
}

int operationSelection() {
    int choice;
    std::cout << "Which operation would you like to do with the matrices?" << std::endl << "Press 1 for addition(+)"
        << std::endl << "Press 2 for subtraction(-)" << std::endl << "Press 3 for multiplication(*)" << std::endl;
    std::cin >> choice;
    return choice;
}

int main() {
    std::string choice;
    std::cout << "Would you like to work with string or numerical matrices? Press 1 for numerical and anything else for string..." << std::endl;
    std::cin >> choice;

    auto [num_rows, num_cols] = matrixDimensions();
    
    if (choice == "1") {
        Matrix<int> firstMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, firstMatrix, 1);

        Matrix<int> secondMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, secondMatrix, 2);

        Matrix<int> result(num_rows, num_cols);
        switch (operationSelection()) {
            case 1:
                result = firstMatrix + secondMatrix;
                break;
            case 2:
                result = firstMatrix - secondMatrix;
                break;
            case 3:
                result = firstMatrix * secondMatrix;
                break;
            default:
                std::cout << "Wrong input! Closing the program";
                return 0;
        }

        std::cout << "Resultant matrix has data as follows: " << std::endl;
        result.displayData();
    }
    else {
        Matrix<std::string> firstMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, firstMatrix, 1);

        Matrix<std::string> secondMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, secondMatrix, 2);

        Matrix<std::string> result(num_rows, num_cols);
        switch (operationSelection()) {
            case 1:
                result = firstMatrix + secondMatrix;
                break;
            case 2:
                result = firstMatrix - secondMatrix;
                break;
            case 3:
                result = firstMatrix * secondMatrix;
                break;
            default:
                std::cout << "Wrong input! Closing the program! " << std::endl;
                return 0;
        }

        std::cout << "Resultant matrix has data as follows: " << std::endl;
        result.displayData();
    }
    
    return 0;
}
