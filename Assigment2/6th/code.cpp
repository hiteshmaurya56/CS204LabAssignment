#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low + (high - low) / 2];

    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

void quicksortMedianPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        quicksortMedianPivot(arr, low, partitionIndex);
        quicksortMedianPivot(arr, partitionIndex + 1, high);
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int num;
    fin >> num;
    vector<int> numbers(num);
    for (int i = 0; i < num; i++)
        fin >> numbers[i];

    quicksortMedianPivot(numbers, 0, numbers.size() - 1);

    for (const auto &n : numbers)
    {
        fout << n << " ";
    }

    fin.close();
    fout.close();

    return 0;
}
