#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

int main()
{
    int t = 2;
    ofstream outFile("input.txt");
    if (!outFile.is_open())
    {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }
    while (t--)
    {
        cout << "Enter the number of elements in array " << 2-t  << endl;
        int numRandomNumbers = 100000; // Change this to the desired number of random numbers
        cin >> numRandomNumbers;
        int numbers[numRandomNumbers];
        // Seed the random number generator
        random_device rd;
        mt19937 gen(rd());

        // Define the range of random numbers (here, from 1 to 100)
        uniform_int_distribution<int> distribution(1, 1000000);

        // Generate and write random numbers to the file
        outFile << numRandomNumbers << endl;
        for (int i = 0; i < numRandomNumbers; ++i)
        {
            numbers[i] = distribution(gen);
        }
        sort(numbers, numbers + numRandomNumbers);
        for (int i = 0; i < numRandomNumbers; i++)
            outFile << numbers[i] << ' ';
        outFile << endl;
    }
    outFile.close();
    cout << "Random numbers generated and written to input.txt" << endl;

    return 0;
}
