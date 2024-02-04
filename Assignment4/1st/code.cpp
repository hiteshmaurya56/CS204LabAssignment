#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

vector<int> input();
long long countInversions(vector<int> &, int, int);

int main()
{
    cin.open("input.txt");
    cout.open("output.txt");
    vector<int> v = input();
    long long ans = countInversions(v, 0, v.size() - 1);
    cout << ans;
    cin.close();
    cout.close();
    return 0;
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

long long countInversions(vector<int> &v, int s, int e)
{
    if (s == e)
        return 0;

    int i, j, k, m = (s + e) / 2;
    k = 0;
    long long cnt = countInversions(v, s, m) + countInversions(v, m + 1, e);
    vector<int> a(e - s + 1);
    i = s, j = m + 1;
    while (k < e - s + 1)
    {
        if (j > e || (i <= m && v[i] < v[j]))
            a[k++] = v[i++];
        else
        {
            cnt += m - i + 1;
            a[k++] = v[j++];
        }
    }
    for (k = 0; k < e - s + 1; k++)
        v[s + k] = a[k];
    return cnt;
}
