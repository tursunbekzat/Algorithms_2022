#include <iostream>
#include <vector>
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

    string pat;
    cin >> pat;

    vector<int> p(pat.size());

    computeLPSArray(pat, p);

    // for (int i : p)
    //     cout << i << " ";
    // cout << "\n";

    cout << pat.size() - p[p.size() - 1] << "\n";
    return 0;
}