#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    fstream fin, fout;
    fin.open("input.txt");
    int n;
    fin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        fin >> vec[i];
    fin.close();
    int max, secMax;
    max = secMax = 0;

    for (int i = 0; i < n; i++)
        if (vec[i] > max)
        {
            secMax = max;
            max = vec[i];
        }
        else if (vec[i] > secMax)
            secMax = vec[i];
            
    fout.open("output.txt");
    fout << max + secMax;
    fout.close();
}