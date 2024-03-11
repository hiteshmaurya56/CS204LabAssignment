#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;
ifstream cin;
ofstream cout;

vector<vector<int>> input();
vector<int> findArticulationNodes(vector<vector<int>> &);
vector<vector<int>> findBridges(vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    vector<vector<int>> v = input();
    cin.close();
    vector<vector<int>> bridges = findBridges(v);
    vector<int> articulationNodes = findArticulationNodes(v);
    cout.open("output.txt");
    cout << "Articulation Nodes: " << endl;
    for (int node : articulationNodes)
        cout << node << " ";
    cout << endl;
    cout << "Bridges: " << endl;
    for (vector<int> v : bridges)
        cout << v[0] << " " << v[1] << endl;
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
        v[d].push_back(c);
    }
    return v;
}

void dfs(vector<vector<int>> &v, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges, int node, int parent, int &timer)
{
    low[node] = tin[node] = timer++;
    for (int it : v[node])
    {
        if (it == parent)
            continue;
        if (tin[it] == -1)
            dfs(v, tin, low, bridges, it, node, timer);
        if (low[it] > tin[node])
            bridges.push_back({node, it});
        low[node] = min(low[node], low[it]);
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &v)
{
    int n = v.size(), timer = 0;
    vector<int> tin(n, -1), low(n);
    vector<vector<int>> bridges;
    dfs(v, tin, low, bridges, 0, -1, timer);
    return bridges;
}

void dfs(vector<vector<int>> &v, vector<int> &tin, vector<int> &low, unordered_set<int> &nodes, int node, int parent, int &timer)
{
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it : v[node])
    {
        if (it == parent)
            continue;
        if (tin[it] == -1)
        {
            dfs(v, tin, low, nodes, it, node, timer);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
                nodes.insert(node);
            child++;
        }
        else
            low[node] = min(low[node], tin[it]);
    }
    if (parent == -1 && child > 1)
        nodes.insert(node);
}

vector<int> findArticulationNodes(vector<vector<int>> &v)
{
    int i, n = v.size(), timer = 0;
    vector<int> tin(n, -1), low(n);
    unordered_set<int> nodes;
    vector<int> ans;
    for (i = 0; i < n; i++)
        if (tin[i] == -1)
            dfs(v, tin, low, nodes, i, -1, timer);
    for (int it : nodes)
        ans.push_back(it);
    return ans;
}
