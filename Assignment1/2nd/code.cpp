#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, vector<vector<int>> &dp, int maxWeight, int i)
{
    if (i < 0)
        return 0;
        
    if (dp[i][maxWeight] != -1)
        return dp[i][maxWeight];
    int exclude, include = 0;
    exclude = knapsack(weights, values, dp, maxWeight, i - 1);
    if (maxWeight >= weights[i])
        include = values[i] + knapsack(weights, values, dp, maxWeight - weights[i], i - 1);
    return dp[i][maxWeight] = max(include, exclude);
}

int main()
{
    fstream fin, fout;
    fin.open("input.txt");
    int n, maxWeight;
    fin >> n >> maxWeight;
    vector<int> weights(n), values(n);
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    for (int i = 0; i < n; i++)
        fin >> weights[i];
    for (int i = 0; i < n; i++)
        fin >> values[i];
    fin.close();

    int ans = knapsack(weights, values, dp, maxWeight, n - 1);
    fout.open("output.txt");
    fout << ans;
    fout.close();
}