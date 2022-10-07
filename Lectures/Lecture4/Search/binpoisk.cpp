#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int x = 3, y = 7, N = 50;
    int l = 0;
    int ans=0;
    int r = 2e2;
    cout << r <<endl;
    while(l<=r){
        int mid = (l+r) / 2;
        int res = mid/x + mid/y;
        cout << res << " " << mid << endl;
        if(res < N){
            l = mid + 1;
        }else{
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
}