#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long uns;

char getChar(uns prefix, int index)
{
    int ascii = prefix / pow(2, index);
    return char(ascii + 97);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector <uns> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    string s = "";
    s += getChar(v[0], 0);
    for (int i = 1; i < n; i++)
        s += getChar(v[i] - v[i - 1], i);

    cout << s;

}