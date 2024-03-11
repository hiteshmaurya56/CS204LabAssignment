#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

vector<vector<int>> input();
bool detectCycle(vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    vector<vector<int>> v = input();
    cin.close();
    bool cycle = detectCycle(v);
    cout.open("output.txt");
    cout << cycle;
    cout.close();
    return 0;
}

vector<vector<int>> input()
{
    int c, d, n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    while (m--)
    {
        cin >> c >> d;
        v[c].push_back(d);
    }
    return v;
}

bool dfs(vector<vector<int>> &v, vector<int> &vis, vector<int> &visit, int i)
{
    if (visit[i])
        return 1;
    if (vis[i])
        return 0;
    vis[i] = visit[i] = 1;
    for (auto d : v[i])
        if (dfs(v, vis, visit, d))
            return 1;
    visit[i] = 0;
    return 0;
}

bool detectCycle(vector<vector<int>> &v)
{
    int i, n = v.size();
    vector<int> vis(n), visit(n);
    for (i = 0; i < n; i++)
        if (dfs(v, vis, visit, i))
            return 1;
    return 0;
}