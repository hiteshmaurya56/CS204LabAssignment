#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin;
ofstream cout;

vector<vector<int>> input();
int findMaxPath(vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    vector<vector<int>> v = input();
    cin.close();
    int maxPath = findMaxPath(v);
    cout.open("output.txt");
    cout << maxPath;
    cout.close();

    return 0;
}

vector<vector<int>> input()
{
    int i, n, m, c, d;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (i = 0; i < m; i++)
    {
        cin >> c >> d;
        v[c].push_back(d);
    }
    return v;
}

int dfs(vector<vector<int>> &v, vector<int> &pathL, int i)
{
    if (pathL[i] != -1)
        return pathL[i];
    pathL[i] = 0;
    for (auto d : v[i])
    {
        pathL[i] = max(pathL[i], 1 + dfs(v, pathL, d));
    }

    return pathL[i];
}

int findMaxPath(vector<vector<int>> &v)
{
    int i, n = v.size();
    vector<int> pathL(n, -1);
    for (i = 0; i < n; i++)
        dfs(v, pathL, i);
    return *max_element(pathL.begin(), pathL.end());
}