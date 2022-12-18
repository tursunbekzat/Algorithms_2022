#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int a[n][n];
    for (int i(0); i < n; i++)
        for (int j(0); j < n; j++)
            cin >> a[i][j];

    for (int i(0); i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        if (a[x][y] && a[x][z] && a[y][z])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}