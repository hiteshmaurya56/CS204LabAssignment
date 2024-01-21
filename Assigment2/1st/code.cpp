#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> mergeArrays(vector<int> &, vector<int> &);
vector<int> unionArrays(vector<int> &, vector<int> &);
vector<int> interArrays(vector<int> &, vector<int> &);

int main()
{
    int n, m, i;
    fstream fin, fout;
    fin.open("input.txt");
    fout.open("output.txt");
    fin >> n;
    vector<int> vec1(n);
    for (i = 0; i < n; i++)
        fin >> vec1[i];
    fin >> m;
    vector<int> vec2(m);
    for (i = 0; i < m; i++)
        fin >> vec2[i];
    vector<int> merg, uni, inter;
    merg = mergeArrays(vec1, vec2);
    uni = unionArrays(vec1, vec2);
    inter = interArrays(vec1, vec2);
fout<<"Merged Array:"<<endl;
    for (int val : merg)
        fout << val << " ";
    fout << endl;
fout<<"Union Array:"<<endl;
    for (int val : uni)
        fout << val << " ";
    fout << endl;
fout<<"Intersection Array:"<<endl;
    for (int val : inter)
        fout << val << " ";
    fin.close();
    fout.close();
    return 0;
}

vector<int> mergeArrays(vector<int> &vec1, vector<int> &vec2)
{
    int i, j, k, n, m;
    n = vec1.size(), m = vec2.size();
    i = j = k = 0;
    vector<int> vec(m + n);

    while (k < (m + n))
    {
        if (j == m || vec1[i] <= vec2[j])
            vec[k++] = vec1[i++];
        else
            vec[k++] = vec2[j++];
    }

    return vec;
}

vector<int> unionArrays(vector<int> &vec1, vector<int> &vec2)
{
    int i, j, n, m;
    n = vec1.size(), m = vec2.size();
    i = j = 0;
    vector<int> vec;

    while (i < n || j < m)
    {
        if (j == m || vec1[i] < vec2[j])
            vec.push_back(vec1[i++]);
        else if (i == n || vec2[j] < vec1[i])
            vec.push_back(vec2[j++]);
        else
        {
            vec.push_back(vec1[i++]);
            j++;
        }
    }

    return vec;
}

vector<int> interArrays(vector<int> &vec1, vector<int> &vec2)
{
    int i, j, n, m;
    vector<int> vec;
    n = vec1.size(), m = vec2.size();
    i = j = 0;
    while (i < n && j < m)
    {
        if (vec1[i] == vec2[j])
        {
            vec.push_back(vec1[i++]);
            j++;
        }
        else if (vec1[i] < vec2[j])
            i++;
        else
            j++;
    }

    return vec;
}
