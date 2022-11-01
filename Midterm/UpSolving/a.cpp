#include <iostream>
using namespace std;

unsigned long long heap[200010];
int sz = 0;

void heapify(int i)
{
    int left = i + i + 1;
    int right = i + i + 2;

    int mx = i;

    if (left < sz && heap[left] > heap[mx])
    {
        mx = left;
    }
    if (right < sz && heap[right] > heap[mx])
    {
        if(mx == left){
            swap(heap[left], heap[right]);
            mx = left;
        }
        else{
            mx = right;
        }
    }

    if (mx != i)
    {
        swap(heap[i], heap[mx]);
        heapify(mx);
    }
}

void build()
{
    for (int i = sz / 2; i >= 0; i--)
    {       
        heapify(i);
    }
}

void print()
{
    for (int i = 0; i < sz; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int count(){
    int cnt = 0;
    for(int i(0);i<sz;i++){
        if(i+2 > sz){
            break;
        }
        if(heap[i + 1] < heap[i+2]){
            cnt++;
        }
    }
    return cnt;
};

int main()
{
    cin >> sz;
    for (int i = 0; i < sz; i++)
    {
        cin >> heap[i];
    }

    build();

    print();
    cout << count()<<endl;
    return 0;

}