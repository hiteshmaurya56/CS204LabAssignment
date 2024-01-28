#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main()
{
    int numRandomNumbers = 100000; 
    cout<<"Enter size of Array:\n";
    cin >> numRandomNumbers;
    ofstream outFile("input.txt");

    if (!outFile.is_open())
    {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(1, 1000000);

    outFile << numRandomNumbers << endl;
    for (int i = 0; i < numRandomNumbers; ++i)
    {
        int randomNumber = distribution(gen);
        if ((randomNumber % 3) & 1)
            randomNumber *= -1;
        outFile << randomNumber << " ";
    }

    outFile.close();
    cout << "Random numbers generated and written to output.txt" << endl;

    return 0;
}
