////Task 1
//
//#include <iostream>
//#include <fstream>
//#include <string>
// 
//int main() 
//{
//    std::ifstream fin("inputexc1.txt");
//    if (!fin) 
//    {
//        std::cerr << "Error occurred when opening a file.\n";
//        return 1;
//    }
//
//    // === Working with a one-dimensional array ===
//    std::string type1;
//    fin >> type1;
//    if (type1 != "1D") 
//    {
//        std::cerr << "Expected block 1D.\n";
//        return 1;
//    }
//
//    int n;
//    fin >> n;
//    if (n <= 0) 
//    {
//        std::cerr << "Incorrect array length.\n";
//        return 1;
//    }
//
//    int* arr1D = new int[n];
//    for (int i = 0; i < n; ++i) 
//    {
//        fin >> arr1D[i];
//    }
//
//    std::cout << "One-dimensional array - elements with even indices:\n";
//    for (int i = 0; i < n; i += 2) 
//    {
//        std::cout << arr1D[i] << " ";
//    }
//    std::cout << "\n";
//    delete[] arr1D;
//
//    // === Working with a two-dimensional array ===
//    std::string type2;
//    fin >> type2;
//    if (type2 != "2D") 
//    {
//        std::cerr << "Expected block 2D.\n";
//        return 1;
//    }
//
//    int rows, cols;
//    fin >> rows >> cols;
//    if (rows <= 0 || cols <= 0) 
//    {
//        std::cerr << "Incorrect array dimensions.\n";
//        return 1;
//    }
//
//    int** arr2D = new int* [rows];
//    for (int i = 0; i < rows; ++i) 
//    {
//        arr2D[i] = new int[cols];
//        for (int j = 0; j < cols; ++j) 
//        {
//            fin >> arr2D[i][j];
//        }
//    }
//
//    std::cout << "Two-dimensional array - elements with even sum of indices:\n";
//    for (int i = 0; i < rows; ++i) 
//    {
//        for (int j = 0; j < cols; ++j) 
//        {
//            if ((i + j) % 2 == 0) 
//            {
//                std::cout << arr2D[i][j] << " ";
//            }
//        }
//    }
//    std::cout << "\n";
//
//    for (int i = 0; i < rows; ++i) 
//    {
//        delete[] arr2D[i];
//    }
//    delete[] arr2D;
//
//    return 0;
//}

//Task 2

#include <iostream>
#include <fstream>
#include <cmath>

const double EPSILON = 1e-9; // comparison accuracy for real numbers

bool isDivisible(double a, double b) 
{
    if (std::abs(b) < EPSILON) return false; // Divide by 0 protection
    return std::abs(std::fmod(a, b)) < EPSILON;
}

int main() 
{
    std::ifstream fin("inputexc2.txt");
    if (!fin) 
    {
        std::cerr << "Error occurred when opening a file.\n";
        return 1;
    }

    int n;
    fin >> n;

    if (n < 2) 
    {
        std::cerr <<"Not enough data (n must be more than 2).\n";
        return 1;
    }

    double* arr = new double[n];
    for (int i = 0; i < n; ++i) 
    {
        fin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < n - 1; ++i) 
    {
        if (isDivisible(arr[i], arr[i + 1])) 
        {
            ++count;
        }
    }

    std::cout << "Number of pairs where the previous element is a multiple of the next: " << count << "\n";

    delete[] arr;
    return 0;
}
