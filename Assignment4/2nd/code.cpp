#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

vector<int> input();
double findMedianSortedArrays(vector<int> &, vector<int> &);

int main()
{
    vector<int> arr1, arr2;
    cin.open("input.txt");
    cout.open("output.txt");
    arr1 = input();
    arr2 = input();

    double ans = findMedianSortedArrays(arr1, arr2);
    cout << ans;
    cin.close();
    cout.close();
}

vector<int> input()
{
    int i, n;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    return v;
}

double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    if (arr1.size() > arr2.size())
        return findMedianSortedArrays(arr2, arr1);
    int s1, s2, e1, e2, m1, m2, n, n1, n2, s, e;
    n1 = arr1.size(), n2 = arr2.size();
    n = (n1 + n2 + 1) / 2;
    s = 0, e = n1;
    while (e >= s)
    {
        m1 = (e + s) / 2;
        m2 = n - m1;
        s1 = s2 = INT32_MIN;
        e1 = e2 = INT32_MAX;
        if (m1 > 0)
            s1 = arr1[m1 - 1];
        if (m1 < n1)
            e1 = arr1[m1];
        if (m2 > 0)
            s2 = arr2[m2 - 1];
        if (m2 < n2)
            e2 = arr2[m2];
        if (s1 > e2)
            e = m1 - 1;
        else if (s2 > e1)
            s = m1 + 1;
        else
        {
            if ((n1 + n2) & 1)
                return max(s1, s2);
            return (max(s1, s2) + min(e1, e2)) / 2.0;
        }
    }
    return 0;
}