#include <iostream>
#include <vector>
#include <map>
using namespace std;

void computeLPSArray(string pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, vector<string>> mpv;
    string boss;
    cin >> boss;
    int n;
    cin >> n;
    boss[0] += 32;

    string ans;
    int MAX = -1;
    bool changed = false;
    while (n--)
    {
        string employee;
        cin >> employee;
        if (employee[0] < 92)
        {
            employee[0] += 32;
            changed = true;
        }
        vector<int> p(employee.size() + boss.size() + 1);
        computeLPSArray(employee + '&' + boss, p);
        int m = p[p.size() - 1];
        if (m == 0) continue;
        if (m > MAX) MAX = m;
        if (changed) employee[0] -= 32;
        mpv[m].push_back(employee);
    }
    
    cout << mpv[MAX].size() << '\n';
    for (string i : mpv[MAX])
    {
        cout << i << '\n';
    }

}