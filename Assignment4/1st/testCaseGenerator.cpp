#include <iostream>
#include <fstream>
#include <random>
using namespace std;
int main()
{
    int numRandomNumbers = 100000; // Change this to the desired number of random numbers
    cout << "Enter the number of numbers to be generated:\n";
    cin >> numRandomNumbers;
    ofstream outFile("input.txt");

    if (!outFile.is_open())
    {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Define the range of random numbers (here, from 1 to 100)
    uniform_int_distribution<int> distribution(1, 1000000);

    // Generate and write random numbers to the file
    outFile << numRandomNumbers << endl;
    for (int i = 0; i < numRandomNumbers; ++i)
    {
        int randomNumber = distribution(gen);
        outFile << randomNumber << " ";
    }

    outFile.close();
    cout << "Random numbers generated and written to input.txt" << endl;

    return 0;
}
