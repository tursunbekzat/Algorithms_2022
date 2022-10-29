#include <iostream>
using namespace std;

unsigned long long heap[200010000];
int q = 0;

void heapify(int i)
{
    int left = i + i + 1;
    int right = i + i + 2;

    int mx = i;

    if (left < q && heap[left] < heap[mx])   mx = left;
    if (right < q && heap[right] < heap[mx]) mx = right;
    if (mx != i)
    {
        swap(heap[i], heap[mx]);
        heapify(mx);
    }
}

void build()
{
    for (int i = q / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

void insert(unsigned long long value)
{
    heap[q++] = value;
    int i = q - 1;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[i] < heap[p])
        {
            swap(heap[i], heap[p]);
            i = p;
        }
        else
        {
            break;
        }
    }
}

void deleteMin()
{
    swap(heap[0], heap[q - 1]);
    q--;
    heapify(0);
}

void print()
{
    for (int i = 0; i < q; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapsort()
{
    build();
    while (q > 1)
    {
        swap(heap[0], heap[q - 1]);
        q--;
        heapify(0);
    }
}

void PrintSum(int cnt){
    long long sum = 0;
    for(int i(0);i< 3;i++){
        sum += i;
    }
}

int main()
{
    int k, j = 0, x;
    cin >> q >> k;
    string s;
    int cnt = 0, count = 0;
    for(int i(0);i<q;i++){
        heap[i] = 0;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> s;
        if(s == "insert"){
            cin >> x;
            count++;
            heap[j] = x;
            j++;
            heapsort();
        }else{
            if(count > k){
                cnt++;
            }
            PrintSum(cnt);
        }
    }

    build();
    return 0;
}