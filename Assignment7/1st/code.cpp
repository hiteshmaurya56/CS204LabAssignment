#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;

int knapsack( vector<int> &, vector<int> &, vector<vector<int>> &, int, int);

int main()
{
    int i, n, capacity, ans;
    cin.open("input.txt");
    cin >> n;
    vector<int> weight(n), cost(n);
    for (i = 0; i < n; i++)
        cin >> weight[i];
    for (i = 0; i < n; i++)
        cin >> cost[i];
    cin >> capacity;
    cin.close();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    ans = knapsack( weight, cost, dp, capacity, n - 1);
    cout.open("output.txt");
    cout << ans << endl;
    cout.close();
    return 0;
}

int knapsack(vector<int> &weight, vector<int> &cost, vector<vector<int>> &dp, int capacity, int i)
{
    if (i < 0 || capacity <= 0)
        return 0;
    if (dp[i][capacity] != -1)
        return dp[i][capacity];
    int exc, inc = 0;
    exc = knapsack(weight, cost, dp, capacity, i - 1);
    if (capacity >= weight[i])
        inc = cost[i] + knapsack(weight, cost, dp, capacity - weight[i], i - 1);
    return dp[i][capacity] = max(inc, exc);
}