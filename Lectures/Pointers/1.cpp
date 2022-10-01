#include <iostream>
using namespace std;

int main()
{
    /*
    int n = 2025;
    int *p = &n;

    cout << "n = " << n << "; address: " << p << endl;
    cout << "p = " << p << "; address: " << &p << "*p = "<< *p << endl;

    *p = 2024;
    cout << "n = " << n << "; address: " << p << endl;
    cout << "p = " << p << "; address: " << &p << "*p = "<< *p << endl;
    */

    /*
     double d[4] = {2.1, 3.4, 5.6, 7.8};
     double *p = d;

     cout << *p << endl;

     p++;
     cout << *p << endl;
     */

    int n, m;
    cin >> n >> m;

    int **p = new int*[n];

    for(int i(0);i<n;i++){
        p[i] = new int[m];
    }

    for (int i(0); i < n; i++)
    {
        for (int j(0); j < m; j++)
        {
            p[i][j] = 0;
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    for (int i(0); i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}