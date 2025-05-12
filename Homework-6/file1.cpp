//Task 1

//#include <iostream>
//#include <fstream>

//int main() {
    //std::ifstream inputFile("input.txt"); // input file
    //if (!inputFile) {
        //std::cerr << "An error occured during opening a file" << std::endl;
        //return 1;
    //}

    //int rows, cols;
    //inputFile >> rows >> cols;

    //int size = rows * cols;
    //int* array = new int[size];

    //for (int i = 0; i < size; ++i) {
        //inputFile >> array[i];
    //}
    //inputFile.close();

    //std::cout << "Elements with even indeces: " << std::endl;
    //for (int i = 0; i < size; ++i) {
        //int row = i / cols;
        //int col = i % cols;
        //if ((row + col) % 2 == 0) {
            //std::cout << array[i] << " ";
        //}
    //}
    //std::cout << std::endl;

    //delete[] array;

    //return 0;
//}

#include <iostream>
#include <fstream>


int main() {
    std::ifstream inputFile("input2.txt"); // input file
    if (!inputFile) {
        std::cerr << "Error occured when opening a file" << std::endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            inputFile >> array[i][j];
        }
    }
    inputFile.close();

    std::cout << "Elements with even indeces:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i + j) % 2 == 0) {
                std::cout << array[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;

    // Releasing memory
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}