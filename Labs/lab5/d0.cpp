// C++ code to demonstrate the working of
// make_heap(), front()
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Initializing a vector
    vector<int> v1;

    int n, k, x;
    cin >> n >> k;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        v1.push_back(-1 * x);
    }
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());

    vector<int>::iterator it1;
    // for (int &x : v1)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    int cnt = 0;
    unsigned long long ans = 0;
    // cout << (-1) * v1.front() << " " << k << endl;
    while ((-1) * v1.front() < k)
    {    
        cnt++;
        if (v1.size() < 2)
        {
            cout << -1 << endl;
            return 0;
        }
        unsigned long long a = v1.front();
        swap(v1.front(), v1.back());
        v1.pop_back();
        make_heap(v1.begin(), v1.end());
        // for (int &x : v1)
        // {
        //     cout << x << " ";
        // }
        // cout << endl << cnt << endl;
        unsigned long long b = v1.front();
        swap(v1.front(), v1.back());
        v1.pop_back();
        v1.push_back(a + 2 * b);
        make_heap(v1.begin(), v1.end());
        // for (int &x : v1)
        // {
        //     cout << x << " ";
        // }
        // cout << endl << cnt << endl;
    }
    cout << cnt << endl;
    //  // using push_back() to enter element
    // // in vector
    // v1.push_back(50);

    // // using push_heap() to reorder elements
    // push_heap(v1.begin(), v1.end());

    // // Displaying the maximum element of heap
    // // using front()
    // cout << "The maximum element of heap after push is : ";
    // cout << v1.front() << endl;

    //  // using pop_heap() to delete maximum element
    // pop_heap(v1.begin(), v1.end());
    // v1.pop_back();

    // // Displaying the maximum element of heap
    // // using front()
    // cout << "The maximum element of heap after pop is : ";
    // cout << v1.front() << endl;

    // cout << "The heap elements are : ";
    // for (int &x : v1)
    //    cout << x << " ";
    // cout << endl;

    // // sorting heap using sort_heap()
    // sort_heap(v1.begin(), v1.end());

    //  // Displaying heap elements
    // cout << "The heap elements after sorting are : ";
    // for (int &x : v1)
    //    cout << x << " ";

    // // Declaring heap iterator
    // vector<int>::iterator it1;

    // // Checking if container is heap
    // // using is_heap()
    // is_heap(v1.begin(), v1.end())?
    // cout << "The container is heap ":
    // cout << "The container is not heap";
    // cout << endl;

    // // using is_heap_until() to check position
    // // till which container is heap
    // auto it = is_heap_until(v1.begin(), v1.end());

    // // Displaying heap range elements
    // cout << "The heap elements in container are : ";
    // for (it1=v1.begin(); it1!=it; it1++)
    //    cout << *it1 << " ";

    return 0;
}
