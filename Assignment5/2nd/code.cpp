#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

int minThrow(int, int *);

int main()
{
    cin.open("input.txt");
    cout.open("output.txt");
    int i, n;
    cin >> n;
    int arr[2 * n];
    for (i = 0; i < n; i++)
        cin >> arr[i * 2] >> arr[i * 2 + 1];
    int ans = minThrow(n, arr);
    cout << ans;
    cin.close();
    cout.close();
    return 0;
}

int minThrow(int m, int *a)
{
    int j, i, n = 31;
    vector<vector<int>> v(n);
    for (i = 0; i < m; i++)
    {
        v[a[2 * i]].push_back(a[2 * i + 1]);
    }
    vector<int> vis(n, 100);
    vis[1] = 0;
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j < n && j <= i + 6; j++)
        {
            vis[j] = min(vis[j], vis[i] + 1);
            for (auto d : v[j])
            {
                if (d < j)
                    vis[j] = 100;
                vis[d] = min(vis[d], vis[i] + 1);
            }
        }
    }
    if (vis[30] == 100)
        return -1;
    return vis[30];
}