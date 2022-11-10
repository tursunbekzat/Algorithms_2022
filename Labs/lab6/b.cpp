#include <iostream>
#include <deque>
using namespace std;

void insert(deque<int> *d, int n)
{
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        (*d).push_back(x);
    }
}

void quicksort(deque<int> *d, int l, int r)
{
    if (r < 1 || l >= r)
    {
        return;
    }
    int j = r;
    while (l < j)
    {
        if ((*d)[l] > (*d)[r])
        {
            while (j > l)
            {
                if ((*d)[j] <= (*d)[r]){
                    swap((*d)[l], (*d)[j]);
                }
                j--;
            }
        }
        l++;
    }
    quicksort(&(*d), 0, l - 1);
    quicksort(&(*d), l, r);
}

void print(deque<int> d)
{
    if(d.size() == 0){
        return;
    }
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void check_common(deque<int> d1, deque<int> d2){
    if(d1.empty() || d2.empty()){
        return;
    }
    while(!d1.empty() && !d2.empty()){
        if(d2.front() < d1.front()){
            d2.pop_front();
        }
        else if(d2.front() > d1.front()){
            d1.pop_front();
        }
        else{
            cout << d1.front() << " ";
            d1.pop_front();
            d2.pop_front();
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    deque<int> d1, d2;

    cin >> n >> m;

    insert(&d1, n);
    insert(&d2, m);

    // print(d1);
    // print(d2);

    quicksort(&d1, 0, n - 1);
    quicksort(&d2, 0, m - 1);

    // print(d1);
    // print(d2);

    // cout << d1.back() << "\n";

    check_common(d1, d2);

    return 0;
}