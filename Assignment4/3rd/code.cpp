#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin;
ofstream cout;

vector<int> input();
int kthLargestElement(vector<int> &, int);

int main()
{
    cin.open("input.txt");
    cout.open("output.txt");
    vector<int> v = input();
    int ans, k;
    cin >> k;
    ans = kthLargestElement(v, k);
    cout << ans;
    cin.close();
    cout.close();
    return 0;
}

vector<int> input()
{
    int i, n;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    return v;
}

int kthLargestElement(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int i, n = v.size();
    for (i = 0; i < k; i++)
        pq.push(v[i]);
    for (i; i < n; i++)
    {
        pq.push(v[i]);
        pq.pop();
    }
    return pq.top();
}
