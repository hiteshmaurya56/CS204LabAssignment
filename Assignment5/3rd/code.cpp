#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

bool twoCliques(int n, vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    cout.open("output.txt");
    int n, m, i;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(2));
    for (i = 0; i < m; i++)
        cin >> v[i][0] >> v[i][1];
    bool ans = twoCliques(n, v);
    cout << ans;
    cin.close();
    cout.close();
    return 0;
}

bool dfs(vector<vector<int>> &v, vector<int> &vis, int i, int k)
{
    if (vis[i] != -1)
        return vis[i] == k;
    vis[i] = k;
    k = 1 - k;
    for (auto d : v[i])
    {
        if (!dfs(v, vis, d, k))
            return 0;
    }
    return 1;
}
bool twoCliques(int n, vector<vector<int>> &edgeList)
{
    vector<vector<int>> a(n), v(n);
    for (auto e : edgeList)
    {
        a[e[0]].push_back(e[1]);
        a[e[1]].push_back(e[0]);
    }
    int i, j, m, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            m = a[i].size();
            for (k = 0; k < m; k++)
                if (j == a[i][k])
                    break;
            if (m == k)
                v[i].push_back(j);
        }
    }
    vector<int> vis(n, -1);
    for (i = 0; i < n; i++)
    {
        if (vis[i] == -1 && !dfs(v, vis, i, 0))
            return 0;
    }
    return 1;
}