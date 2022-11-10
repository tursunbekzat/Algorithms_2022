#include <iostream>
#include <vector>
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
    int i = l;
    int j = r;
    string g = vpp[r].second.second;
    // for (; i < j; i++)
    while (i < j)
    {
        if (vpp[i].second.second == g)
        {
            if (vpp[i].second.first == vpp[r].second.first)
            {
                if (vpp[i].first > vpp[r].first)
                {
                    swap(vpp[i], vpp[r]);
                    continue;
                }
            }
            else if (vpp[i].second.first > vpp[r].second.first)
            {
                swap(vpp[i], vpp[r]);
                continue;
            }
        }
        if (vpp[i].second.second > g)
        {
            // for (; j >= i; j--)
            while (j >= i)
            {
                if (vpp[j].second.second <= g)
                {
                    swap(vpp[i], vpp[j]);
                    j--;
                    break;
                }
                j--;
            }
        }
        i++;
        // cout << "Sorting Process\n";
        // print();
    }
    quicksorty(0, i - 1);
    // cout << i << "\n
    quicksorty(i, r);
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