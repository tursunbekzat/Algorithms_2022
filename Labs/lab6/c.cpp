#include <iostream>
#include <deque>
using namespace std;

deque<int> pos;

void insert(deque<int> *d, int n)
{
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        (*d).push_back(x);
    }
}

// void quicksort(deque<int> *d, int l, int r)
// {
//     if (r < 1 || l >= r)
//     {
//         return;
//     }
//     int j = r;
//     while (l < j)
//     {
//         if ((*d)[l] > (*d)[r])
//         {
//             while (j > l)
//             {
//                 if ((*d)[j] <= (*d)[r])
//                 {
//                     swap((*d)[l], (*d)[j]);
//                 }
//                 j--;
//             }
//         }
//         l++;
//     }
//     quicksort(&(*d), 0, l - 1);
//     quicksort(&(*d), l, r);
// }

int partition(deque<int> *d, int low, int high)
{
    int pivot = (*d)[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if ((*d)[j] < pivot) {
            i++; // increment index of smaller element
            swap((*d)[i], (*d)[j]);
        }
    }
    swap((*d)[i + 1], (*d)[high]);
    return (i + 1);
}

void quicksort(deque<int> *d, int low, int high)
{
    if (low < high) {
        int pi = partition(&(*d), low, high);
        quicksort(&(*d), low, pi - 1);
        quicksort(&(*d), pi + 1, high);
    }
}

void print(deque<int> d)
{
    if (d.size() == 0)
    {
        return;
    }
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int find_abs_val(deque<int> d)
{
    int m = 100000000;
    for (int i(0); i < d.size() - 1; i++)
    {
        int a = abs( d[i] - d[i + 1] );
        if(a == m){
            pos.push_back(i);
        }
        if ( a < m ){
            while(!pos.empty()){
                pos.pop_back();
            }
            pos.push_back(i);
            m = a;
            
        }
    }
    return m;
}

void printanswer(int m, deque<int> d){
    for(int i(0);i<pos.size();i++){
        cout << d[pos[i]] << " " << d[pos[i] + 1] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    deque<int> d1;

    cin >> n;

    insert(&d1, n);

    // print(d1);

    quicksort(&d1, 0, n - 1);

    // print(d1);

    int m = find_abs_val(d1);

    printanswer(m, d1);

    return 0;
}