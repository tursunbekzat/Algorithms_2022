#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i(2); i < n; i++)
    {
        if (n % i == 0)
        {
            bool ok = true;
            for (int j(2); j * j <= i; j++)
            {
                if(i % j == 0){
                    ok = false;
                }
            }
            if(ok){
                cnt++;
            }
            
        }
    }
    cout << cnt << endl;
}