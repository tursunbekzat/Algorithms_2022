#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void print()
{
    for (int s : v)
    {
        cout << s << " ";
    }
    cout << "\n";
}
void quicksorty(int l, int r)
{
    if (l >= r or r < 1)
        return;
    int i = l;
    int j = r;
    int g = v[r];
    while (i < j)
    {
        if (v[i] > g)
        {
            while (j > i)
            {
                if (v[j] <= g)
                {
                    swap(v[i], v[j]);
                    j--;
                    break;
                }
                j--;
            }
        }
        if (j <= l)
            break;
        i++;
    }
    quicksorty(0, i - 1);
    quicksorty(i, r);
}

void quicksortr(int l, int r)
{
    if (l >= r)
        return;
    int i = l;
    int j = r - 1;
    int g = v[r];
    while (i < j)
    {
        if (v[i] < g)
        {
            while (j > i)
            {
                if (v[j] > g)
                {
                    swap(v[i], v[j]);
                    j--;
                    break;
                }
                j--;
            }
        }
        i++;
    }
    swap(v[i], v[r]);
    print();
    quicksortr(0, i - 1);
    quicksortr(i, r);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;

    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    quicksorty(0, n - 1);

    print();

    // quicksortr(0, n - 1);

    // print();

    return 0;
}