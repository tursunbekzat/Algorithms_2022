#include<bits/stdc++.h>
using namespace std;

vector<pair<string, pair<string, string>>> vpp;
vector<int> v;

void init(int n)
{
    for (int i(0); i < n; i++)
    {
        vpp.push_back(make_pair("0", make_pair("0", "0")));
    }
}

void split(string data, int j)
{
    int i = 0;
    string day = "";
    string month = "";
    string year = "";

    for (int i(0); i < data.size(); i++)
    {
        if (i < 2)
            day += data[i];
        else if (i > 2 && i < 5)
            month += data[i];
        else if (i > 5)
            year += data[i];
    }

    vpp[j].first = day;
    vpp[j].second.first = month;
    vpp[j].second.second = year;
}

void print()
{
    for (int i(0); i < vpp.size(); i++)
    {
        cout << vpp[i].first << "-" << vpp[i].second.first << "-" << vpp[i].second.second << "\n";
    }
}

void quicksorty(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int h = r;
    bool ok = true;
    while (l < h)
    {
        if (vpp[l].second.second == vpp[r].second.second)
        {
            if (vpp[l].second.first == vpp[r].second.first)
            {
                if (vpp[l].first > vpp[r].first)
                {
                    swap(vpp[l], vpp[r]);
                    // continue;
                }
            }
            else if (vpp[l].second.first > vpp[r].second.first)
            {
                swap(vpp[l], vpp[r]);
                // continue;
            }
        }
        else if (vpp[l].second.second > vpp[r].second.second)
        {
            while (h > l)
            {
                if (vpp[h].second.second <= vpp[r].second.second)
                {
                    swap(vpp[l], vpp[h]);
                    // h--;
                    break;
                }
                h--;
            }
        }
        l++;
        // cout << "Sorting Process\n";
        // print();
    }
    quicksorty(0, l - 1);
    quicksorty(l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string data;

    init(n);

    int i = 0;
    while (i < n)
    {
        cin >> data;
        split(data, i);
        i++;
    }

    // cout << "Initial data\n";
    // print();

    quicksorty(0, n - 1);

    // cout << "Sorted data\n";
    print();

    return 0;
}