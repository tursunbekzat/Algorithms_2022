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
    if(l >= r)
        return;
    int h = r;
    while (l < h){
        if(v[l] > v[r]){
            while(h > l){
                if(v[h] <= v[r]){
                    swap(v[l], v[h]);
                    h--;
                    break;
                }
                h--;
            }
        }
        l++;
    }
    cout << "\nSorting process:\n";
    print();
    quicksorty(0, l - 1);
    quicksorty(l, r);
}

void quicksortr(int l, int r)
{
    if(l >= r)
        return;
    int h = r;
    while (l < h){
        if(v[l] < v[r]){
            while(h > l){
                if(v[h] >= v[r]){
                    swap(v[l], v[h]);
                    h--;
                    break;
                }
                h--;
            }
        }
        l++;
    }
    cout << "\nSorting process:\n";
    print();
    quicksortr(0, l - 1);
    quicksortr(l, r);
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

    cout << "\nInitial vector\n";
    print();

    quicksorty(0, n - 1);

    // cout << "\nSorted vector\n";
    // print();

    quicksortr(0, n - 1);
    print();

    return 0;
}