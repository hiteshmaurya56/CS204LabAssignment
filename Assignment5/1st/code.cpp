#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

int findMaxArea(vector<vector<int>> &);

vector<vector<int>> input()
{
    int i, j, n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> v[i][j];
    return v;
}

int main()
{
    cin.open("input.txt");
    cout.open("output.txt");
    vector<vector<int>> v = input();
    int ans = findMaxArea(v);
    cout << ans;
    cin.close();
    cout.close();
    return 0;
}

int dfs(vector<vector<int>> &a, int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || !a[i][j])
        return 0;
    a[i][j] = 0;
    vector<int> v = {-1, 0, 1};
    int l, r, e = 1;
    for (l = 0; l < 3; l++)
    {
        for (r = 0; r < 3; r++)
            e += dfs(a, n, m, i + v[l], j + v[r]);
    }
    return e;
}

int findMaxArea(vector<vector<int>> &a)
{
    int i, j, n, m, e = 0;
    n = a.size();
    m = a[0].size();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j])
            {
                e = max(dfs(a, n, m, i, j), e);
            }
        }
    }
    return e;
}