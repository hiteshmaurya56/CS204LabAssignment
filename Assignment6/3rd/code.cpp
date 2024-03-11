#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream cin;
ofstream cout;

vector<vector<int>> input();
int stronglyConnectedComponents(vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    vector<vector<int>> v = input();
    cin.close();
    int cnt = stronglyConnectedComponents(v);
    cout.open("output.txt");
    cout << cnt;
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

void dfs(vector<vector<int>> &v, vector<int> &vis, stack<int> &st, int i)
{
    if (vis[i])
        return;
    vis[i] = 1;
    for (auto d : v[i])
        dfs(v, vis, st, d);
    st.push(i);
}

void dfs(vector<vector<int>> &a, vector<int> &vis, int i)
{
    if (vis[i])
        return;
    vis[i] = 1;
    for (auto d : a[i])
        dfs(a, vis, d);
}

int stronglyConnectedComponents(vector<vector<int>> &v)
{
    int i, cnt = 0, n = v.size();
    vector<vector<int>> a(n);
    for (i = 0; i < n; i++)
    {
        for (int d : v[i])
            a[d].push_back(i);
    }

    vector<int> vis(n);
    stack<int> st;
    for (i = 0; i < n; i++)
        dfs(v, vis, st, i);

    for (int &d : vis)
        d = 0;
    while (st.size())
    {
        if (!vis[st.top()])
        {
            dfs(a, vis, st.top());
            cnt++;
        }
        st.pop();
    }
    return cnt;
}