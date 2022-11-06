#include <iostream>
using namespace std;

int sz = 0;
char letters[100000];
char vowels[6] = {'a', 'e', 'o', 'i', 'u', 'y'};

bool binarysearch(char c, int l, int r)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (vowels[m] > c)
        {
            r = m - 1;
        }
        else if (vowels[m] < c)
        {
            l = m + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int partition(int l, int r)
{
    int pivot = letters[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        cout << "i = " << letters[i] << " j = " << letters[j] << "\n";
        if (!binarysearch(letters[j], 0, 5) && binarysearch(pivot, 0, 5))
        {
            // if (letters[j] < pivot)
            // {
            //     i++;
            //     // cout << "i = " << letters[i] << " j = " << letters[j] << "\n";
            //     swap(letters[i], letters[j]);
            // }
            i++;
            swap(letters[i], letters[j]);
        }
        // if (binarysearch(letters[j], 0, 5) && binarysearch(letters[j], 0, 5))
        else
        {
            if (letters[j] < pivot)
            {
                i++;
                // cout << "i = " << letters[i] << " j = " << letters[j] << "\n";
                swap(letters[i], letters[j]);
            }
        }
    }
    swap(letters[i + 1], letters[r]);
    return i + 1;
}

void quicksort(int l, int r)
{
    if (l < r)
    {
        int pi = partition(l, r);
        quicksort(l, pi - 1);
        quicksort(pi + 1, r);
    }
}

void print()
{
    for (auto s : letters)
        cout << s;
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sz;

    for (int i(0); i < sz; i++)
    {
        cin >> letters[i];
    }

    quicksort(0, sz - 1);

    print();

    return 0;
}