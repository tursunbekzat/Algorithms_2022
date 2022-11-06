#include <iostream>
#include <algorithm>
using namespace std;

// b = 0, k = 2
//
//
//
char w[5] = {'4', '2', '1', '6', '3'};
int n = 5;

void quicksort(int l, int r)
{
    int m = r;
    while(l <= r){
        if(w[l] > w[m]){
            while(r > l){
                if(w[r] < w[m]){
                    swap(w[l], w[r]);
                    break;
                }
                r--;
            }
        }
        l++;
    }
    cout << l << "\n";
    quicksort(0, l + 1);
    quicksort(l, m);
}

void print()
{
    for (auto ch : w)
    {
        cout << ch;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    quicksort(0, n - 1);

    print();

    return 0;
}