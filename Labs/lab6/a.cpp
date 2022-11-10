#include <iostream>
using namespace std;

int n;
char w[100000];
char v[5] = {'a', 'e', 'o', 'i', 'u'};

bool find(char c)
{
    for (int i(0); i < 5; i++)
        if (v[i] == c)
            return true;
    return false;
}

void insert()
{
    for (int i(0); i < n; i++)
    {
        cin >> w[i];
    }
}

void print();

void quicksort(int l, int r)
{
    if (r < 1 or l >= r)
        return;
    int j = r;
    while (l < j)
    {
        if (w[l] <= w[r])
        {
            if (!find(w[l]) && find(w[r]))
                swap(w[l], w[r]);
            l++;
            continue;
        }
        else
        {
            if (find(w[l]) && !find(w[r]))
            {
                l++;
                continue;
            }
            while (j > l)
            {
                if (w[j] <= w[r])
                {
                    swap(w[l], w[j]);
                    j--;
                    break;
                }
                j--;
            }
        }
        if (j <= l)
            break;
        l++;
    }
    quicksort(0, l - 1);
    quicksort(l, r);
}

void print()
{
    for (int i(0); i < n; i++)
    {
        cout << w[i];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    insert();

    quicksort(0, n - 1);

    print();

    return 0;
}