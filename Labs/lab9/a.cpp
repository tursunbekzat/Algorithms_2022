#include <bits/stdc++.h>
using namespace std;

void prefix(int m, string s, int p[])
{
    int len = 0;
    int i = 1;
    p[0] = 0;

    while (i < m)
    {
        if (s[i] == s[len])
        {
            len++;
            p[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = p[len - 1];
            else
            {
                p[i] = 0;
                i++;
            }
        }
    }
}

bool kmp(string pat, string txt, int p[])
{
    int n = txt.size();
    int m = pat.size();

    // int p[m];
    // prefix(m, pat, p);

    int i = 0;
    int j = 0;

    for (int i(0);;)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else
        {
            if (i >= n)
                return false;
            else if (j == 0)
                i++;
            else
                j = p[j - 1];
        }
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    string pat, txt;
    cin >> txt >> pat;

    int cnt = 1;

    int n = txt.size();
    int m = pat.size();

    int p[m];
    prefix(m, pat, p);

    while (!kmp(pat, txt, p))
    {
        txt += txt;
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}