//  Есть n дипломов длиной h и шириной w, нам нужно найти len x len квадратного доска которое вместиться дипломы.
#include <iostream>
using namespace std;

// main function
int main()
{
    // count, width, height of diplom
    int n, w, h;
    cin >> n >> w >> h;

    // min pointer for lenth, max pointer for lenth
    long long l = 1, r = 1e9;

    // main loop
    while (l + 1 < r)
    {

        // middle pointer
        long long mid = (l + r) / 2;

        // check if middle more or equal to count of diplom
        if ((mid / w) * (mid / h) >= n)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r;
    return 0;
}