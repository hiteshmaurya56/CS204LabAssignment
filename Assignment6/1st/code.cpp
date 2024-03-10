#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
ifstream cin;
ofstream cout;

vector<vector<int>> input();
vector<int> toposort(vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    vector<vector<int>> adj = input();
    cin.close();
    vector<int> ans = toposort(adj);
    cout.open("output.txt");
    for (int d : ans)
        cout << d << " ";
    cout.close();
    return 0;
}

vector<vector<int>> input()
{
    int i, n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return adj;
}

void dfs(vector<vector<int>> &v, vector<int> &vis, stack<int> &st, int i)
{
    if (vis[i])
        return;
    vis[i] = 1;
    for (auto d : v[i])
        dfs(v, vis, st, d);
    st.push(i);
}

vector<int> toposort(vector<vector<int>> &v)
{
    int i, n = v.size();
    stack<int> st;
    vector<int> topo, vis(n);
    for (i = 0; i < n; i++)
        dfs(v, vis, st, i);

    while (st.size())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}