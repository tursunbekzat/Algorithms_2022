#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n;
vector<pair<pair<string, string>, double>> vpp;

double check_gpa(string s)
{
    if (s == "A+")
        return 4.000;
    if (s == "A")
        return 3.750;
    if (s == "B+")
        return 3.500;
    if (s == "B")
        return 3.000;
    if (s == "C+")
        return 2.500;
    if (s == "C")
        return 2.000;
    if (s == "D+")
        return 1.500;
    if (s == "D")
        return 1.000;
    return 0.000;
}

double found_gpa(int cnt, int i, string data)
{
    int credits = 0;
    double total = 0.000;
    for (int j(i); j < data.size();)
    {
        string score = "";
        int credit;
        double point = 0.000;
        while (data[j] != ' ')
        {
            score += data[j];
            j++;
        }
        j++;
        while (data[j] == ' ')
            j++;
        credit = int(data[j]) - 48;
        j++;
        while (data[j] == ' ')
        {
            j++;
            if (j >= data.size())
                break;
        }
        point += check_gpa(score);
        credits += credit;
        total += point * credit;
        // cout << score << " " << point << " " << credit << " " << credits << " " << total << "\n";
        if (j >= data.size())
            break;
    }
    return (total / credits);
}

void split(string data)
{
    int i = 0, cnt = 0;
    string name = "", surname = "";

    while (1)
    {
        while (data[i] != ' ')
        {
            surname += data[i];
            i++;
        }
        i++;
        while (data[i] == ' ')
            i++;
        while (data[i] != ' ')
        {
            name += data[i];
            i++;
        }
        i++;
        while (data[i] == ' ')
            i++;
        while (data[i] != ' ')
        {
            cnt = data[i];
            i++;
        }
        i++;
        while (data[i] == ' ')
            i++;
        break;
    }

    double gpa = found_gpa(cnt, i, data);

    vpp.push_back(make_pair(make_pair(surname, name), gpa));
}

void print()
{
    for (int i(1); i < vpp.size(); i++)
    {
        cout.precision(4);
        cout << vpp[i].first.first << " " << vpp[i].first.second << " " << vpp[i].second << "\n";
        // stringstream ss;
        // ss << vpp[i].second;
        // string gpa;
        // ss >> gpa;
        // if (gpa.size() > 5)
        // {
        //     cout.precision(4);
        //     cout << vpp[i].first.first << " " << vpp[i].first.second << " " << vpp[i].second << "\n";
        // }
        // else
        // {
        //     if(gpa.size() == 1)
        //         gpa += ".";
        //     while (gpa.size() < 5)
        //         gpa += "0";
        //     cout << vpp[i].first.first << " " << vpp[i].first.second << " " << gpa << "\n";
        // }
    }
}

void quicksort(int l, int r)
{
    if (l >= r)
        return;
    int h = r;
    while (l < h)
    {
        if (vpp[l].first.first == vpp[r].first.first)
        {
            if (vpp[l].first.second == vpp[r].first.second)
            {
                if (vpp[l].first > vpp[r].first)
                {
                    swap(vpp[l], vpp[r]);
                }
            }
            else if (vpp[l].first.first > vpp[r].first.first)
            {
                swap(vpp[l], vpp[r]);
            }
        }
        else if (vpp[l].second > vpp[r].second)
        {
            while (h > l)
            {
                if (vpp[h].second <= vpp[r].second)
                {
                    swap(vpp[l], vpp[h]);
                    break;
                }
                h--;
            }
        }
        l++;
    }
    quicksort(0, l - 1);
    quicksort(l, r);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    string data, d;

    cin >> n;

    for (int i(0); i <= n; i++)
    {
        getline(cin, data);
        split(data);
    }

    quicksort(0, n);

    print();

    return 0;
}
