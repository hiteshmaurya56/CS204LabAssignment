#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
vector<int> input();
pair<int, int> findMinima(vector<int> &);

int main()
{

    fin.open("input.txt");
    vector<int> arr = input();
    pair<int, int> minima = findMinima(arr);
    fout.open("output.txt");
    fout << minima.first << " " << minima.second;
    fin.close();
    return 0;
}

vector<int> input()
{
    int n, i;
    fin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        fin >> arr[i];
    return arr;
}

pair<int, int> findMinima(vector<int> &arr)
{
    pair<int, int> minima = {1e9, 1e9};
    for (int d : arr)
        if (d < minima.first)
        {
            minima.second = minima.first;
            minima.first = d;
        }
        else if (d < minima.second)
            minima.second = d;
    return minima;
}