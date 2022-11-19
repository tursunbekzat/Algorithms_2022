#include <iostream>
#include <vector>
using namespace std;

// int findmax(vector<int> p)
// {
//     int m = -1;
//     for (int i : p)
//     {
//         if (m < i)
//             m = i;
//     }
//     return m;
// }

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

    int n;
    cin >> n;

    string pat;
    int k;
    int max = -1;
    for (int i(0); i < n; i++)
    {
        cin >> pat >> k;
        vector<int> p(pat.size());
        computeLPSArray(pat, p);
        int m = p[p.size()-1];
        cout << m + (pat.size() - m) * k << "\n";
    }

    return 0;
}