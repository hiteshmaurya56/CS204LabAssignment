#include <vector>
#include <fstream>
using namespace std;

ifstream cin;
ofstream cout;

vector<int> input();
long long maxSum(vector<int> &, int, int);

int main()
{
    cin.open("input.txt");
    vector<int> v = input();
    cin.close();
    cout.open("output.txt");
    long long ans = maxSum(v, 0, v.size() - 1);
    cout << ans;
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

long long maxSum(vector<int> &v, int s, int e)
{
    if (e - s < 2)
    {
        if (e == s)
            return v[s];
        if (v[s] < 0 && v[e] < 0)
            return max(v[s], v[e]);
        if (v[s] < 0)
            return v[e];
        if (v[e] < 0)
            return v[s];
        return v[s] + v[e];
    }

    long long left, right, center, l, r, temp;
    int i, n, m = (s + e) / 2;
    left = maxSum(v, s, m - 1);
    right = maxSum(v, m + 1, e);
    l = r = temp = 0;
    n = v.size();
    for (i = m + 1; i < n; i++)
    {
        temp += v[i];
        r = max(r, temp);
    }

    temp = 0;
    for (i = m - 1; i >= 0; i--)
    {
        temp += v[i];
        l = max(l, temp);
    }
    center = v[m] + l + r;
    return max(center, max(left, right));
}