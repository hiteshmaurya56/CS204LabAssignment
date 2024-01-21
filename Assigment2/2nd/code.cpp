#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void sort(vector<int> &, int, int);

int main()
{
    int i, j, n, m;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    fin >> n >> m;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        fin >> arr[i];
    sort(arr, n, m);
    for (int val : arr)
        fout << val << " ";
    fin.close();
    fout.close();
    cout << "finished";
    return 0;
}

void sort(vector<int> &arr, int n, int m)
{
    int i, j, k;
    i = 0, j = n - m;
    while (i < n - m)
    {
        if (arr[i] <= arr[j])
            i++;
        else
        {
            swap(arr[i], arr[j]);
            k = j;
            while (k < n - 1 && arr[k] > arr[k + 1])
            {
                swap(arr[k], arr[k + 1]);
                k++;
            }
        }
    }
}
