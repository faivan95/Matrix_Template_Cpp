#include "matrix_temp.h"
#include <iostream>
#include <type_traits>

template <bool B, typename T, typename F> 
using matrixType = typename std::conditional<B, T, F>::type;

int main() {
    std::cout << "What is the dimension of the first matrix? " << std::endl 
                    << "Please enter in format: {no. of rows} {no. of columns} with a space in between" << std::endl;
    
    int num_rows, num_cols;
    std::cin >> num_rows >> num_cols;
    //std::cout << num_rows << num_cols;
    //Matrix<std::string> first_matrix(num_rows, num_cols);
    bool strCheck = true;  //checks if any of the field in a matrix is a string or not
    matrixType<strCheck, int, double> first_matrix;
    Matrix<std::string> second_matrix(2, 2);

    // first_matrix(0, 0) = "Hello"; first_matrix(0, 1) = "This";
    // first_matrix(1, 0) = "a"; first_matrix(1, 1) = "for";
    std::string temp_data[num_rows][num_cols];
    
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            std::cout << "Input the data at " << i << " " << j << " of the first matrix: " << std::endl;
            std::cin >> temp_data[i][j];    
            if (strCheck == false) {
                strCheck = checkForString(temp_data[i][j]);
            }
        }
        std::cout << std::endl;
    }

    //Determining type of matrix
    if (strCheck == false) {
        Matrix<int> first_matrix(num_rows, num_cols);
    }
    else {
        Matrix<std::string> first_matrix(num_rows, num_cols);
    }

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            first_matrix(i, j) = temp_data[i][j];
        }
        std::cout << std::endl;
    }

    second_matrix(0, 0) = " World!"; second_matrix(0, 1) = " is";
    second_matrix(1, 0) = " check"; second_matrix(1, 1) = " strings!";

    Matrix<std::string> result = first_matrix + second_matrix;


    for (int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getCols(); ++j) {
            std::cout << result(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
