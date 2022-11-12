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

int partition(int low, int high)
{
    string pivot = vpp[high].second.second;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if(vpp[j].second.first == vpp[high].second.first){
            if(vpp[j].first < vpp[high].first){
                swap(vpp[j], vpp[high]);
            }
        }
        if (vpp[j].second.second < pivot)
        {
            i++;
            swap(vpp[i], vpp[j]);
        }
    }
    swap(vpp[i + 1], vpp[high]);
    return (i + 1);
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);

        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
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

    cout << "Initial data\n";
    print();

    quicksort(0, n - 1);

    cout << "Sorted data\n";
    print();

    return 0;
}