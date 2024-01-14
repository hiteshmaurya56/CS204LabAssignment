#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int tsp(vector<vector<int>> &matrix, vector<vector<int>> &dp, int n, int i, int mask)
{
    if (mask == (1 << n) - 1)
        return matrix[i][0];
    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = 1e9;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
            continue;
        ans = min(ans, matrix[i][j] + tsp(matrix, dp, n, j, (mask | (1 << j))));
    }
    return dp[i][mask] = ans;
}

int main()
{
    fstream fin, fout;
    int n;
    fin.open("input.txt");
    fin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> matrix[i][j];
    fin.close();

    int mask = (1 << n) - 1;
    vector<vector<int>> dp(n, vector<int>(mask, -1));
    int ans = tsp(matrix, dp, n, 0, 1);
    fout.open("output.txt");
    fout << ans;
    fout.close();
}