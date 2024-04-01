#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
ifstream cin;
ofstream cout;

struct Job
{
public:
    int id, dead, profit;
};

vector<Job> input();
pair<int, vector<int>> getMaxProfit(vector<Job> &);

int main()
{
    cin.open("input.txt");
    vector<Job> v = input();
    cin.close();
    pair<int, vector<int>> jobs = getMaxProfit(v);
    sort(jobs.second.begin(), jobs.second.end());
    cout.open("ouput.txt");
    cout << "Maximum Profit: " << jobs.first << endl;
    cout << "Jobs done: " << jobs.second.size() << endl;
    cout << "Job IDs: " << endl;
    for (int c : jobs.second)
        cout << c << ' ';
    cout.close();
    return 0;
}

vector<Job> input()
{
    int i, n;
    cin >> n;
    vector<Job> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i].id >> v[i].dead >> v[i].profit;
    return v;
}

struct comp
{
    bool operator()(const Job &a, const Job &b)
    {
        if (a.profit != b.profit)
            return a.profit > b.profit;
        return a.id < b.id;
    }
};

pair<int, vector<int>> getMaxProfit(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.dead <= b.dead; });
    vector<int> jobId;
    set<Job, comp> s;
    Job curJob;
    int i, j, n = jobs.size();
    i = n - 1;
    pair<int, vector<int>> ans;
    j = jobs[n - 1].dead;
    while (j)
    {
        while (i >= 0 && jobs[i].dead >= j)
            s.insert(jobs[i--]);
        j--;
        if (s.empty())
            continue;
        curJob = *s.begin();
        s.erase(s.begin());
        ans.first += curJob.profit;
        ans.second.push_back(curJob.id);
    }
    return ans;
}