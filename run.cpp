#include "matrix_temp.h"
#include <iostream>
//#include <type_traits>
//#include <variant>
//#include <typeinfo>
#include <tuple>

// template <bool B, typename T, typename F> 
// using matrixType = typename std::conditional<B, T, F>::type;
//using matrixType = std::variant<int, std::string>;

std::tuple<size_t, size_t> matrixDimensions() {
    std::cout << "What is the dimension of the first matrix? " << std::endl 
                    << "Please enter {no. of rows} and {no. of columns} with a space or enter in-between:" << std::endl;
    
    size_t num_rows, num_cols;
    std::cin >> num_rows >> num_cols;
    return {num_rows, num_cols};
}

void populateMatrix(size_t rows, size_t cols, Matrix<int>& mat, int matrixNo) {
    std::string temp;
    // std::cout << "int" << std::endl;
    // std::cout << typeid(mat).name() << std::endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Input the data at " << i << " " << j << " of matrix " << matrixNo << ": " << std::endl;
            std::cin >> temp;  
            mat(i, j) = std::stoi(temp);
            //std::cout << "Type of input " << temp_data[i][j] << ": " << typeid(temp_data[i][j]).name() << std::endl;
            // if (checkForString(temp_data[i][j])) {
            //     first_matrix(i, j) = std::stoi(temp_data[i][j]);
            //     continue;
            // }
            // first_matrix(i, j) = temp_data[i][j];
            // if (strCheck == false) {
            //     strCheck = checkForString(temp_data[i][j]);
            // }
        }
    }
}

void populateMatrix(size_t rows, size_t cols, Matrix<std::string>& mat, int matrixNo) {
    // std::cout << "string" << std::endl;
    // std::cout << typeid(mat).name() << std::endl;
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
    //matrixType matT;
    std::string choice;
    std::cout << "Would you like to work with string or numerical matrices? Press 1 for numerical and anything else for string..." << std::endl;
    std::cin >> choice;

    auto [num_rows, num_cols] = matrixDimensions();
    
    if (choice == "1") {
        //matT = 1;
        
        Matrix<int> firstMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, firstMatrix, 1);
        //firstMatrix.displayData();
        Matrix<int> secondMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, secondMatrix, 2);
        //secondMatrix.displayData();
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
        //matT = "string";
        Matrix<std::string> firstMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, firstMatrix, 1);
        firstMatrix.displayData();
        Matrix<std::string> secondMatrix(num_rows, num_cols);
        populateMatrix(num_rows, num_cols, secondMatrix, 2);
        //secondMatrix.displayData();
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



    // std::cout << "What is the dimension of the first matrix? " << std::endl 
    //                 << "Please enter in format: {no. of rows} {no. of columns} with a space in between" << std::endl;
    
    // int num_rows, num_cols;
    // std::cin >> num_rows >> num_cols;
    // //std::cout << num_rows << num_cols;
    
    // // bool strCheck = true;  //checks if any of the field in a matrix is a string or not
    // // matrixType<strCheck, int, double> first_matrix;
    

    // if (true) {
    //     Matrix<std::string> first_matrix(num_rows, num_cols);
    //     Matrix<std::string> second_matrix(2, 2);
    // }
    // else {
    //     Matrix<int> first_matrix(num_rows, num_cols);
    //     Matrix<int> second_matrix(2, 2);
    // }

    // // first_matrix(0, 0) = "Hello"; first_matrix(0, 1) = "This";
    // // first_matrix(1, 0) = "a"; first_matrix(1, 1) = "for";
    // std::string temp_data[num_rows][num_cols];
    
    // for (int i = 0; i < num_rows; ++i) {
    //     for (int j = 0; j < num_cols; ++j) {
    //         std::cout << "Input the data at " << i << " " << j << " of the first matrix: " << std::endl;
    //         std::cin >> temp_data[i][j];  
    //         //std::cout << "Type of input " << temp_data[i][j] << ": " << typeid(temp_data[i][j]).name() << std::endl;
    //         if (checkForString(temp_data[i][j])) {
    //             first_matrix(i, j) = std::stoi(temp_data[i][j]);
    //             continue;
    //         }
    //         first_matrix(i, j) = temp_data[i][j];
    //         // if (strCheck == false) {
    //         //     strCheck = checkForString(temp_data[i][j]);
    //         // }
    //     }
    //     std::cout << std::endl;
    // }

    // //Determining type of matrix
    // // if (strCheck == false) {
    // //     Matrix<int> first_matrix(num_rows, num_cols);
    // // }
    // // else {
    // //     Matrix<std::string> first_matrix(num_rows, num_cols);
    // // }

    // for (int i = 0; i < num_rows; ++i) {
    //     for (int j = 0; j < num_cols; ++j) {
    //         first_matrix(i, j) = temp_data[i][j];
    //     }
    //     std::cout << std::endl;
    // }

    // second_matrix(0, 0) = " World!"; second_matrix(0, 1) = " is";
    // second_matrix(1, 0) = " check"; second_matrix(1, 1) = " strings!";

    // Matrix<std::string> result = first_matrix + second_matrix;


    // for (int i = 0; i < result.getRows(); ++i) {
    //     for (int j = 0; j < result.getCols(); ++j) {
    //         std::cout << result(i, j) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
