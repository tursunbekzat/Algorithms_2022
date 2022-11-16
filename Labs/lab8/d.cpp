#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int rabinKarp(char pattern[], char text[], int q) {
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int cnt = 0;

    for (i = 0; i < m - 1; i++)
        h = (h * 10) % q;
    for (i = 0; i < m; i++) {
        p = (10 * p + pattern[i]) % q;
        t = (10 * t + text[i]) % q;
    }
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cnt++;
        }

        if (i < n - m) {
            t = (10 * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
    return cnt;
}
int main()
{
    int q = 2147483647;
    while (true)
    {
        int n; int num = 0; 
        vector<string> s;
        char pattern[151][100]; char txt[100000];
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pattern[i];
        }
        cin >> txt;
        for (int i = 0; i < n; i++)
        {
            int cnt = rabinKarp(pattern[i], txt, q);
            if (cnt > num)
            {
                s.clear();
                s.push_back(pattern[i]);
                num = cnt;
            }
            else if (cnt == num)
            {
                s.push_back(pattern[i]);
            }
        }
        cout << num << endl;
        for (int i =0;i<s.size(); i++)
        {
            cout << s[i] << endl;
        }
        
    }
}       