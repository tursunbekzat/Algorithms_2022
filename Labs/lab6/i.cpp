#include <iostream>
using namespace std;

int n;
char letters[100];

void quicksort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int h = r;
    while (l < h)
    {
        if (letters[l] > letters[r])
        {
            while (l < h)
            {
                if (letters[h] <= letters[r])
                    swap(letters[l], letters[h]);
                break;
            }
            h--;
        }
        l++;
    }
    quicksort(0, l - 1);
    quicksort(l, r);
}

void print()
{
    for (auto s : letters)
    {
        cout << s;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i(0); i < s.size(); i++)
    {
        letters[i] = s[i];
    }

    // print();

    quicksort(0, s.size() - 1);
    print();

    return 0;
}