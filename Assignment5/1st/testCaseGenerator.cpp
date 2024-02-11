#include <iostream>
#include <vector>
#include <random>
#include <fstream>
using namespace std;
ofstream fout;

// Function to generate a random boolean matrix of size n*m
vector<vector<bool>> generateRandomBooleanMatrix(int n, int m)
{
    // Seed for the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Distribution to generate 0 or 1
    uniform_int_distribution<> dis(0, 1);

    // Create the boolean matrix
    vector<vector<bool>> matrix(n, vector<bool>(m));

    // Fill the matrix with random 0s and 1s
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = dis(gen);
        }
    }

    return matrix;
}

int main()
{
    // Set the size of the matrix (change n and m accordingly)
    int n = 3;
    int m = 4;
    cout << "Enter values of n and m\n";
    cin >> n >> m;
    // Generate a random boolean matrix
    vector<vector<bool>> randomMatrix = generateRandomBooleanMatrix(n, m);

    // Display the generated matrix
    fout.open("input.txt");
    fout << n << " " << m << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            fout << randomMatrix[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
    cout << "Matrix generated successfully.";
    return 0;
}
