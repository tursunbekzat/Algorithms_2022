#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
// using namespace std::chrono;

int getHash(string s)
{
    const int m = 1e9 + 7;
    const int P = 11;
    int p = 1;
    int Hash = 0;
    int n = s.size();
    for (int i(0); i < n; i++)
    {
        Hash = (Hash + (s[i] - 91) * p) % m;
        p = (p * P) % m;
    }
    return Hash;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = high_resolution_clock::now();

    string tape;
    int n;
    cin >> tape >> n;
    vector<string> tapes(n);
    set<int> is;

    int size = tape.size();
    for (int i(0); i < n; i++)
        cin >> tapes[i];
    for (string i : tapes)
    {
        int h = getHash(i);
        for (int j(0); j < size; j++)
        {
            string sub = tape.substr(j, i.size());
            // cout << "sunbstring : " << sub << "\n";
            int h_sub = getHash(sub);
            if (h != h_sub)
                continue;
            if (sub == i)
            {
                // cout << "position is : " << j << "\n";
                int k = i.size();
                int c = 0;
                while (k--)
                {
                    is.insert(j + c);
                    c++;
                }
            }
        }
    }

    // for (auto i : is)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    if (is.size() == tape.size())
        cout << "YES\n";
    else
        cout << "NO\n";

    // time function
    // cout << "\n";

    // auto stop = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop - start);

    // cout << "Time taken by function: "

    //      << duration.count() << " microseconds"
    //      << "\n";
    return 0;
}