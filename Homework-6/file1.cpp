//Task 1

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt"); // input file
    if (!inputFile) {
        std::cerr << "An error occured during opening a file" << std::endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols;

    int size = rows * cols;
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        inputFile >> array[i];
    }
    inputFile.close();

    std::cout << "Elements with even indeces: " << std::endl;
    for (int i = 0; i < size; ++i) {
        int row = i / cols;
        int col = i % cols;
        if ((row + col) % 2 == 0) {
            std::cout << array[i] << " ";
        }
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}