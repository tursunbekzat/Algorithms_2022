#include <iostream>
#include <cmath>
using namespace std;

int countPrime(int n){
    int cnt = 0;
    for(int i(0);i <= sqrt(n);i++){
        if(n % i == 0){
            // cnt++;
            while(n / i){
                n /= i;
                cnt++;
            }
        }
    }
    if(n != 1){
        cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    


    return 0;

}