#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

//Task 1
 
void task1() 
{
    std::ifstream fin("inputexc1.txt");
    if (!fin) 
    {
        std::cerr << "Error occurred when opening a file.\n";
        return;
    }

    // === Working with a one-dimensional array ===
    std::string type1;
    fin >> type1;
    if (type1 != "1D") 
    {
        std::cerr << "Expected block 1D.\n";
        return;
    }

    int n;
    fin >> n;
    if (n <= 0) 
    {
        std::cerr << "Incorrect array length.\n";
        return;
    }

    int* arr1D = new int[n];
    for (int i = 0; i < n; ++i) 
    {
        fin >> arr1D[i];
    }

    std::cout << "One-dimensional array - elements with even indices:\n";
    for (int i = 0; i < n; i += 2) 
    {
        std::cout << arr1D[i] << " ";
    }
    std::cout << "\n";
    delete[] arr1D;

    // === Working with a two-dimensional array ===
    std::string type2;
    fin >> type2;
    if (type2 != "2D") 
    {
        std::cerr << "Expected block 2D.\n";
        return;
    }

    int rows, cols;
    fin >> rows >> cols;
    if (rows <= 0 || cols <= 0) 
    {
        std::cerr << "Incorrect array dimensions.\n";
        return;
    }

    int** arr2D = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr2D[i] = new int[cols];
        for (int j = 0; j < cols; ++j) 
        {
            fin >> arr2D[i][j];
        }
    }

    std::cout << "Two-dimensional array - elements with even sum of indices:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if ((i + j) % 2 == 0) 
            {
                std::cout << arr2D[i][j] << " ";
            }
        }
    }
    std::cout << "\n";

    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr2D[i];
    }
    delete[] arr2D;

}

//Task 2

const double EPSILON = 1e-9; // comparison accuracy for real numbers

bool isDivisible(double a, double b) 
{
    if (std::abs(b) < EPSILON) return false; // Divide by 0 protection
    return std::abs(std::fmod(a, b)) < EPSILON;
}

void task2() 
{
    std::ifstream fin("inputexc2.txt");
    if (!fin) 
    {
        std::cerr << "Error occurred when opening a file.\n";
        return;
    }

    int n;
    fin >> n;

    if (n < 2) 
    {
        std::cerr <<"Not enough data (n must be more than 2).\n";
        return;
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
}

//Task 3

void task3() 
{
    std::ifstream fin("inputexc3.txt");
    if (!fin) 
    {
        std::cerr << "Error occurred when opening a file.\n";
        return;
    }

    int n;
    fin >> n;

    if (n <= 0) 
    {
        std::cerr << "Incorrect array size.\n";
        return;
    }

    // Allocating memory for a two-dimensional array
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = new int[n];
    }

    // Reading an array
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> arr[i][j];

    // Processing: for each line need to find the maximum and change its sign
    for (int i = 0; i < n; ++i) 
    {
        int maxIndex = 0;
        for (int j = 1; j < n; ++j) 
        {
            if (arr[i][j] > arr[i][maxIndex])
                maxIndex = j;
        }
        arr[i][maxIndex] = -arr[i][maxIndex]; // Replace with the opposite
    }

    
    std::cout << "The result is:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Clearing memory
    for (int i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;

}

//Task 4

void task4() 
{
    std::ifstream fin("inputexc4.txt");
    if (!fin)
    {
        std::cerr << "An error ocurred when opening a file.\n";
        return;
    }

    int n;
    fin >> n;

    if (n <= 1)
    {
        std::cerr << "Error! The array size must be greater than 1.\n";
        return;
    }

    // Allocating memory for a two-dimensional array
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i)
        arr[i] = new int[n];

    // Reading an array
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> arr[i][j];

    // New array to store results
    int* result = new int[n];

    // Processing: for each row find the first pair of unequal neighbors
    for (int i = 0; i < n; ++i) 
    {
        result[i] = -1; 
        for (int j = 0; j < n - 1; ++j) 
        {
            if (arr[i][j] != arr[i][j + 1]) 
            {
                result[i] = j;
                break;
            }
        }
    }

    
    std::cout << "Indices of the first unequal pairs in each row:\n";
    for (int i = 0; i < n; ++i)
        std::cout << result[i] << " ";
    std::cout << "\n";

    // Clearing memory
    for (int i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;
    delete[] result;

}

//Task 5

void task5()
{
    std::ifstream fin("inputexc5.txt");
    if (!fin) 
    {
        std::cerr << "Error! Unable to open a file.\n";
        return;
    }

    int n;
    fin >> n;

    if (n <= 0) 
    {
        std::cerr << "Incorrect array size.\n";
        return;
    }

    int* arr = new int[n];

    // Reading the array
    for (int i = 0; i < n; ++i) 
    {
        if (!(fin >> arr[i])) 
        {
            std::cerr << "Error reading array.\n";
            delete[] arr;
            return;
        }
    }

    int d;
    if (!(fin >> d) || d < 0 || d > 9) 
    {
        std::cerr << "Incorrect value of the digit to delete.\n";
        delete[] arr;
        return;
    }

    // Filtering: removing elements whose last digit is d
    int new_size = 0;
    for (int i = 0; i < n; ++i) 
    {
        int last_digit = std::abs(arr[i]) % 10;
        if (last_digit != d) 
        {
            arr[new_size++] = arr[i];
        }
    }

    std::cout << "The result is:\n";
    for (int i = 0; i < new_size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr;
}

//Task 6

void task6() 
{
    std::ifstream fin("inputexc6.txt");
    if (!fin) 
    {
        std::cerr << "Unable to open a file.\n";
        return;
    }

    int rows, cols;
    fin >> rows >> cols;

    if (rows <= 0 || cols <= 0) 
    {
        std::cerr << "Incorrect array dimensions.\n";
        return;
    }

    // Allocating memory for the original array
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];

    // Reading an array
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            fin >> arr[i][j];

    int target;
    fin >> target;

    // Determining which columns to insert new ones before
    bool* insert_before = new bool[cols]();
    int new_cols = cols;

    for (int j = 0; j < cols; ++j) 
    {
        for (int i = 0; i < rows; ++i) 
        {
            if (arr[i][j] == target) 
            {
                insert_before[j] = true;
                ++new_cols;
                break;
            }
        }
    }

    // Allocating memory for a new array
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
        new_arr[i] = new int[new_cols];

    // Forming a new array
    for (int i = 0; i < rows; ++i) 
    {
        int new_j = 0;
        for (int j = 0; j < cols; ++j) 
        {
            if (insert_before[j]) 
            {
                new_arr[i][new_j++] = 0; 
            }
            new_arr[i][new_j++] = arr[i][j]; 
        }
    }

    
    std::cout << "The result is:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < new_cols; ++j) 
        {
            std::cout << new_arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Clearing memory
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
        delete[] new_arr[i];
    }
    delete[] arr;
    delete[] new_arr;
    delete[] insert_before;

}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    
    return 0;
}
