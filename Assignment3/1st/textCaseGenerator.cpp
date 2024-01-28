#include <iostream>
#include <vector>
#include <random>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
// Function to generate a random matrix of given dimensions
vector<vector<int>> generate_random_matrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = distribution(gen);
        }
    }

    return matrix;
}

// Function to print a matrix
void print_matrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            fout << value << " ";
        }
        fout << endl;
    }
}

int main()
{
    int rows_A, cols_A, rows_B, cols_B;
    fout.open("input.txt");
    cout << "Enter the dimensions of matrix A (rows and columns): ";
    cin >> rows_A >> cols_A;

    cout << "Enter the dimensions of matrix B (rows and columns): ";
    cin >> rows_B >> cols_B;

    if (cols_A != rows_B)
    {
        cout << "Error: Matrices cannot be multiplied due to incompatible dimensions" << endl;
        return EXIT_FAILURE;
    }
    fout << rows_A << " " << cols_A << " " << rows_B << " " << cols_B << endl;
    // Generate random matrices
    vector<vector<int>> matrix_A = generate_random_matrix(rows_A, cols_A);
    vector<vector<int>> matrix_B = generate_random_matrix(rows_B, cols_B);

    // Print the generated matrices
    cout << "\nGenerated Matrix A:" << endl;
    print_matrix(matrix_A);

    cout << "\nGenerated Matrix B:" << endl;
    print_matrix(matrix_B);
    fout.close();
    return 0;
}
