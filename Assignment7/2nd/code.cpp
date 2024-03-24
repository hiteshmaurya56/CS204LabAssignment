#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
ifstream cin;
ofstream cout;

vector<vector<int>> input();
pair<int, vector<int>> getMaxProfit(vector<vector<int>> &);

int main()
{
    cin.open("input.txt");
    vector<vector<int>> v = input();
    cin.close();
    cout.open("ouput.txt");
    pair<int, vector<int>> jobs = getMaxProfit(v);
    cout << "Maximum Profit: " << jobs.first << endl;
    cout << "Jobs done:" << endl;
    for (int c : jobs.second)
        cout << c << ' ';
    cout.close();
    return 0;
}

vector<vector<int>> input()
{
    int i, n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    return v;
}

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    return a[2] > b[2];
}

pair<int, vector<int>> getMaxProfit(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comp);
    for (int i = 0; i < jobs.size(); i++)
        cout << jobs[i][0] << ' ' << jobs[i][1] << ' ' << jobs[i][2] << endl;
    vector<int> jobId;
    int i, profit = 0, preJob = -1, n = jobs.size();
    for (i = 0; i < n; i++)
    {
        if (jobs[i][1] == preJob)
            continue;
        preJob = jobs[i][1];
        jobId.push_back(jobs[i][0]);
        profit += jobs[i][2];
    }
    return {profit, jobId};
}