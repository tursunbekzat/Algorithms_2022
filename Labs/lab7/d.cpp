#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<string>> vs;

vector<string> getWords(string s)
{
    vector<string> sv;
    string h = "";
    for (auto d : s)
    {
        if (d == ' ')
        {
            sv.push_back(h);
            h = "";
        }
        else
            h += d;
    }
    sv.push_back(h);
    return sv;
}

bool comparator(string s1, string s2)
{
    if (s1.size() < s2.size())
        return 1;
    if (s1.size() > s2.size())
        return 0;

    for (int i(0); i < s1.size(); i++)
    {
        if (s1[i] < s2[i])
            return 1;
        if (s1[i] > s2[i])
            return 0;
    }

    return 1;
}

void print()
{
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < vs[i].size(); j++)
            cout << vs[i][j] << " ";
        cout << "\n";
    }
}

void merge_sorted_arr(vector<string> &v, int l, int r)
{
    int mid = (l + r) / 2;
    int i1 = l, i2 = mid + 1, i = l;

    vector<string> mv(r - l + 1);
    while (i1 <= mid && i2 <= r)
    {
        if (comparator(v[i1], v[i2]))
        {
            mv[i - l] = v[i1];
            i1++;
        }
        else
        {
            mv[i - l] = v[i2];
            i2++;
        }
        i++;
    }

    if (i1 <= mid)
        for (; i1 <= mid; i1++, i++)
            mv[i - l] = v[i1];
    else
        for (; i2 <= r; i2++, i++)
            mv[i - l] = v[i2];

    for (i = l; i <= r; i++)
        v[i] = mv[i - l];
}

void MergeSort(vector<string> &v, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    MergeSort(v, l, mid);
    MergeSort(v, mid + 1, r);
    merge_sorted_arr(v, l, r);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> n;
    string s;
    cin.ignore();
    for (int i(0); i < n; i++)
    {
        getline(cin, s);
        vector<string> split = getWords(s);
        MergeSort(split, 0, split.size() - 1);
        vs.push_back(split);
    }

    print();

    return 0;
}