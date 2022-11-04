#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap
{
    int size;
    vector<int> v;

    MaxHeap();
    void insert(int val);
    int update(int i);
    void print();
    void shiftup(int i);
};

MaxHeap ::MaxHeap()
{
    size = 0;
}

void MaxHeap ::shiftup(int i)
{
    if (i == 0)
        return;
    int p = (i - 1) / 2;
    if (v[p] < v[i])
    {
        swap(v[p], v[i]);
        shiftup(p);
    }
}

void MaxHeap ::insert(int val)
{
    size++;
    if (size > v.size())
        v.push_back(val);
    else
        v[size - 1] = val;
    shiftup(size - 1);
}

int MaxHeap ::update(int i)
{
    if (i == 0)
        return 0;
    int p = (i - 1) / 2;
    if(v[p] < v[i]){
        swap(v[p], v[i]);
        return update(p);
    }
    return i;
}

void MaxHeap :: print(){
    for(int s : v){
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    MaxHeap heap;

    int k;
    for(int i(0);i<n;i++){
        cin >> k;
        heap.insert(k);
    }

    int q;
    cin >> q;

    int i, val;
    while(q--){
        cin >> i >> val;
        heap.v[i - 1] += val;
        cout << heap.update(i - 1) + 1 << "\n";
    }

    heap.print();

    return 0;
}